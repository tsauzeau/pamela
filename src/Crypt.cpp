//
// Created by thomas on 10/21/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/types.h>
#include <libcryptsetup.h>

#include <sys/mount.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <malloc.h>

#include "Logger.hh"
#include "Crypt.hh"

static int _read_mk(const char *file, char **key, int keysize) {
    int fd;
    *key = (char *) malloc(keysize);
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

Crypt::Crypt(std::string &name) : name(name) {
    logger.debug << "Create the Crypt object";
    containerPath = "/opt/containers/" + name + ".img";
    keyPath = "/opt/containers/" + name + ".key";
}

Crypt::~Crypt() {
    logger.debug << "Destruct the Crypt object";
}

int Crypt::close() {
    logger.debug << "Try to close the container for: " + name;
    struct crypt_device *cd = NULL;
    int r;
    r = crypt_init_by_name(&cd, name.c_str());
    if (r == 0)
        r = crypt_deactivate(cd, name.c_str());
    crypt_free(cd);
    return r;
    return 0;
}

int Crypt::open() {
    logger.debug << "Try to open the container for: " + name;
    struct crypt_device *cd;
    struct crypt_active_device cad;
    int r;

    r = crypt_init(&cd, containerPath.c_str());
    if (r < 0) {
        printf("crypt_init() failed for %s.\n", containerPath.c_str());
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
                                     name.c_str(),   /* device name to activate */
                                     CRYPT_ANY_SLOT,/* which slot use (ANY - try all) */
                                     "foo", 3,      /* passphrase */
                                     0); /* flags */
    if (r < 0) {
        printf("Device %s activation failed.\n", name.c_str());
        crypt_free(cd);
        return r;
    }
    printf("LUKS device %s/%s is active.\n", crypt_get_dir(), name.c_str());
    printf("\tcipher used: %s\n", crypt_get_cipher(cd));
    printf("\tcipher mode: %s\n", crypt_get_cipher_mode(cd));
    printf("\tdevice UUID: %s\n", crypt_get_uuid(cd));
    r = crypt_get_active_device(cd, name.c_str(), &cad);
    if (r < 0) {
        printf("Get info about active device %s failed.\n", name.c_str());
        crypt_deactivate(cd, name.c_str());
        crypt_free(cd);
        return r;
    }
    printf("Active device parameters for %s:\n"
                   "\tDevice offset (in sectors): %" PRIu64 "\n"
                   "\tIV offset (in sectors)    : %" PRIu64 "\n"
                   "\tdevice size (in sectors)  : %" PRIu64 "\n"
                   "\tread-only flag            : %s\n",
           name.c_str(), cad.offset, cad.iv_offset, cad.size,
           cad.flags & CRYPT_ACTIVATE_READONLY ? "1" : "0");

    crypt_free(cd);
    return 0;
}

int Crypt::format() {
    struct crypt_device *cd;
    struct crypt_params_luks1 params;
    int r;
    char *key = NULL;
    int keysize;

    keysize = 256 / 8;
    r = crypt_init(&cd, containerPath.c_str());
    if (r < 0) {
        printf("crypt_init() failed for %s.\n", containerPath.c_str());
        return r;
    }

    r = _read_mk(keyPath.c_str(), &key, keysize);
    params.hash = "sha1";
    params.data_alignment = 0;
    params.data_device = NULL;
    r = crypt_format(cd, CRYPT_LUKS1, "aes", "xts-plain64", NULL, key, keysize, &params);

    if (r < 0) {
        printf("crypt_format() failed on device %s\n", crypt_get_device_name(cd));
        crypt_free(cd);
        return r;
    }
    r = crypt_keyslot_add_by_volume_key(cd, CRYPT_ANY_SLOT, key, keysize, "foo", 3);

    printf("Format ok\n");
    return 0;
}