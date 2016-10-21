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
    r = crypt_load(cd, CRYPT_LUKS1, NULL);
    if (r < 0) {
        printf("crypt_load() failed on device %s.\n", crypt_get_device_name(cd));
        crypt_free(cd);
        return r;
    }
    r = crypt_activate_by_passphrase(cd, containerPath.c_str(), CRYPT_ANY_SLOT, "foo", 3, 0);
    if (r < 0) {
        printf("Device %s activation failed.\n", containerPath.c_str());
        crypt_free(cd);
        return r;
    }
    printf("LUKS device %s/%s is active.\n", crypt_get_dir(), containerPath.c_str());
    printf("\tcipher used: %s\n", crypt_get_cipher(cd));
    printf("\tcipher mode: %s\n", crypt_get_cipher_mode(cd));
    printf("\tdevice UUID: %s\n", crypt_get_uuid(cd));
    r = crypt_get_active_device(cd, containerPath.c_str(), &cad);
    if (r < 0) {
        printf("Get info about active device %s failed.\n", containerPath.c_str());
        crypt_deactivate(cd, containerPath.c_str());
        crypt_free(cd);
        return r;
    }
    printf("Active device parameters for %s:\n"
                   "\tDevice offset (in sectors): %" PRIu64 "\n"
                   "\tIV offset (in sectors)    : %" PRIu64 "\n"
                   "\tdevice size (in sectors)  : %" PRIu64 "\n"
                   "\tread-only flag            : %s\n",
           containerPath.c_str(), cad.offset, cad.iv_offset, cad.size,
           cad.flags & CRYPT_ACTIVATE_READONLY ? "1" : "0");

    crypt_free(cd);
    return 0;
}

int Crypt::format() {
    return 0;
}
