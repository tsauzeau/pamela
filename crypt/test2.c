#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>
#include <libcryptsetup.h>

#include <sys/stat.h>
#include <fcntl.h>

static int _read_mk(const char *file, char **key, int keysize)
{
  int fd;
  *key = malloc(keysize);
  if (!*key)
    return -1;
  fd = open(file, O_RDONLY);
  if (fd == -1) {
    printf("Cannot read keyfile %s.\n", file);
    goto fail;
  }
  if ((read(fd, *key, keysize) != keysize)) {
    printf("Cannot read %d bytes from keyfile %s.\n", keysize, file);
    close(fd);
    goto fail;
  }
  close(fd);
  return 0;
 fail:
  free(*key);
  *key = NULL;
  return -1;
}

int	crypt(int argc, char *argv[])
{
  struct crypt_device *cd;
  struct crypt_params_luks1 params;
  int r;
  char *key = NULL;
  int keysize;

  keysize = 256 / 8;
  r = crypt_init(&cd, argv[1]);
  if (r < 0 ) {
    printf("crypt_init() failed for %s.\n", argv[1]);
    return r;
  }

  r = _read_mk(argv[2], &key, keysize);
  params.hash = "sha1";
  params.data_alignment = 0;
  params.data_device = NULL;
  r = crypt_format(cd,            /* crypt context */
		   CRYPT_LUKS1,   /* LUKS1 is standard LUKS header */
		   "aes",         /* used cipher */
		   "xts-plain64", /* used block mode and IV generator*/
		   NULL,          /* generate UUID */
		   key,          /* generate volume key from RNG */
		   keysize,       /* 256bit key - here AES-128 in XTS mode, size is in bytes */
		   &params);      /* parameters above */

  if(r < 0) {
    printf("crypt_format() failed on device %s\n", crypt_get_device_name(cd));
    crypt_free(cd);
    return r;
  }
  r = crypt_keyslot_add_by_volume_key(cd,                 /* crypt context */
				      CRYPT_ANY_SLOT,     /* just use first free slot */
				      key,               /* use internal volume key */
				      keysize,                  /* unused (size of volume key) */
				      "foo",              /* passphrase - NULL means query*/
				      3);                 /* size of passphrase */

  printf("All ok");
}


int	activate(int argc, char *argv[])
{
  struct crypt_device *cd;
  struct crypt_active_device cad;
  int r;

  r = crypt_init(&cd, argv[1]);
  if (r < 0 ) {
    printf("crypt_init() failed for %s.\n", argv[1]);
    return r;
  }
  r = crypt_load(cd,              /* crypt context */
		 CRYPT_LUKS1,     /* requested type */
		 NULL);           /* additional parameters (not used) */
  if (r < 0) {
    printf("crypt_load() failed on device %s.\n", crypt_get_device_name(cd));
    crypt_free(cd);
    return r;
  }
  r = crypt_activate_by_passphrase(cd,            /* crypt context */
				   "toto",   /* device name to activate */
				   CRYPT_ANY_SLOT,/* which slot use (ANY - try all) */
				   "foo", 3,      /* passphrase */
				   CRYPT_ACTIVATE_READONLY); /* flags */
  if (r < 0) {
    printf("Device %s activation failed.\n", "toto");
    crypt_free(cd);
    return r;
  }
  printf("LUKS device %s/%s is active.\n", crypt_get_dir(), "toto");
  printf("\tcipher used: %s\n", crypt_get_cipher(cd));
  printf("\tcipher mode: %s\n", crypt_get_cipher_mode(cd));
  printf("\tdevice UUID: %s\n", crypt_get_uuid(cd));
  r = crypt_get_active_device(cd, "toto", &cad);
  if (r < 0) {
    printf("Get info about active device %s failed.\n", "toto");
    crypt_deactivate(cd, "toto");
    crypt_free(cd);
    return r;
  }
  printf("Active device parameters for %s:\n"
	 "\tDevice offset (in sectors): %" PRIu64 "\n"
	 "\tIV offset (in sectors)    : %" PRIu64 "\n"
	 "\tdevice size (in sectors)  : %" PRIu64 "\n"
	 "\tread-only flag            : %s\n",
	 "toto", cad.offset, cad.iv_offset, cad.size,
	 cad.flags & CRYPT_ACTIVATE_READONLY ? "1" : "0");

  crypt_free(cd);
  return 0;
}


int main(int argc, char *argv[])
{
  crypt(argc, argv);
  activate(argc, argv);
}
