#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>
#include <libcryptsetup.h>

static char *readcontent(const char *filename)
{
  char *fcontent = NULL;
  int fsize = 0;
  FILE *fp;

  fp = fopen(filename, "r");
  if(fp) {
    fseek(fp, 0, SEEK_END);
    fsize = ftell(fp);
    rewind(fp);

    fcontent = (char*) malloc(sizeof(char) * fsize);
    fread(fcontent, 1, fsize, fp);

    fclose(fp);
  }
  return fcontent;
}

int	main(int argc, char *argv[])
{

  struct crypt_device *cd;
  struct crypt_params_luks1 params;
  int r;
  
  r = crypt_init(&cd, argv[1]);
  if (r < 0 ) {
    printf("crypt_init() failed for %s.\n", argv[1]);
    return r;
  }  
  params.hash = "sha1";
  params.data_alignment = 0;
  params.data_device = NULL;
  r = crypt_format(cd,            /* crypt context */
		   CRYPT_LUKS1,   /* LUKS1 is standard LUKS header */
		   "aes",         /* used cipher */
		   "xts-plain64", /* used block mode and IV generator*/
		   NULL,          /* generate UUID */
		   NULL,          /* generate volume key from RNG */
		   256/8,       /* 256bit key - here AES-128 in XTS mode, size is in bytes */
		   &params);      /* parameters above */

  if(r < 0) {
    printf("crypt_format() failed on device %s\n", crypt_get_device_name(cd));
    crypt_free(cd);
    return r;
  }
}
