//
// Created by thomas on 10/21/16.
//

#ifndef PAMELA_CRYPT_H
#define PAMELA_CRYPT_H

# include <cstdio>
# include <cstdlib>
# include <iostream>

class Crypt {
public:
    Crypt(std::string &name);
    ~Crypt();

public:
    int open();
    int close();

private:
    int format();

private:
    const std::string name;
    std::string containerPath;
    std::string keyPath;
};


#endif //PAMELA_CRYPT_H
