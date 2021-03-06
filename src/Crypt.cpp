//
// Created by thomas on 10/21/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <libcryptsetup.h>
#include <string>
#include <fstream>
#include <sys/mount.h>
#include <fcntl.h>
#include "Logger.hh"
#include "Crypt.hh"
#include "Utils.hh"


int Crypt::blankFile(int size) {
    std::vector<char> empty(1024, 0);
    std::ofstream ofs(containerPath.c_str(), std::ios::binary | std::ios::out);

    for (int i = 0; i < 1024 * size; i++) {
        if (!ofs.write(&empty[0], empty.size())) {
            std::cerr << "problem writing to file" << std::endl;
            return 255;
        }
    }
}

Crypt::Crypt(std::string &name) : name(name) {
    logger.debug << "Create the Crypt object";
    containerPath = "/opt/containers/" + name + ".img";
    keyPath = "/opt/containers/" + name + ".key";
}

Crypt::~Crypt() {
    logger.debug << "Destruct the Crypt object";
}

int Crypt::mountPart() {
    std::string from("/dev/mapper/" + name);
    std::string to("/home/" + name);
    logger.debug << "Mounting partition to: " + to;
    mount(from.c_str(), to.c_str(), "ext4", 0, NULL);
}

int Crypt::uMountPart() {
    std::string cmd("umount /home/" + name);
    logger.debug << "Unmounting: " + cmd;
    system(cmd.c_str());
}

int Crypt::makeRight() {
    std::string right("chown -R " + name + ":" + name + " /home/" + name);
    logger.debug << "Making correct rights: " + right;
    system(right.c_str());
}

int Crypt::close() {
    logger.debug << "Try to close the container for: " + name;
    this->uMountPart();
    struct crypt_device *cd = NULL;
    int r;
    r = crypt_init_by_name(&cd, name.c_str());
    if (r == 0)
        r = crypt_deactivate(cd, name.c_str());
    crypt_free(cd);
    return r;
}

int Crypt::activate() {
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
    r = crypt_activate_by_passphrase(cd, name.c_str(), CRYPT_ANY_SLOT, "foo", 3, 0);
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
    std::string key;
    int keysize;

    keysize = 256 / 8;
    r = crypt_init(&cd, containerPath.c_str());
    if (r < 0) {
        printf("crypt_init() failed for %s.\n", containerPath.c_str());
        return r;
    }

    r = utils.read_mk(keyPath, key, keysize);
    params.hash = "sha1";
    params.data_alignment = 0;
    params.data_device = NULL;
    r = crypt_format(cd, CRYPT_LUKS1, "aes", "xts-plain64", NULL, key.c_str(), keysize, &params);

    if (r < 0) {
        printf("crypt_format() failed on device %s\n", crypt_get_device_name(cd));
        crypt_free(cd);
        return r;
    }
    r = crypt_keyslot_add_by_volume_key(cd, CRYPT_ANY_SLOT, key.c_str(), keysize, "foo", 3);

    logger.debug << "Format ok";
    return 0;
}

int Crypt::create() {
    std::string input;
    logger.debug << "Ask for the container size";
    std::cout
            << "Hello new user, welcome in the beautiful world of the security and paranoia, what is the size of your container ? (in Mo):"
            << std::endl;
    getline(std::cin, input);
    logger.debug << "Create a container with a size of " + input + "Mb in " + containerPath;
    std::cout << "Create the image, this take some time, please wait..." << std::endl;
    blankFile(std::stoi(input));
    std::cout << "Create the key" << std::endl;
    std::ofstream out(this->keyPath);
    out << utils.randomKey();
    out.close();
    std::cout << "Format the image, this take some time, please wait..." << std::endl;
    this->format();
}

int Crypt::open() {
    if (name == "root") {
        logger.debug << "Wohou he's root, a kind of voodoo, don't talk to him otherwise he launch a sort on us !";
    } else if (utils.exist(containerPath.c_str())) {
        logger.debug << "User already have a container (" + containerPath + ")";
        this->activate();
        this->mountPart();
    } else {
        logger.debug << "User is new, Wouhou !  (" + containerPath + ")";
        this->create();
        this->activate();
        std::string cmd("/dev/mapper/" + name);
        utils.mkfs(cmd);
        this->mountPart();
        this->makeRight();
    }
    return 0;
}
