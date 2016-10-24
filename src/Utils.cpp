#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <string>
#include <fstream>
#include <sys/mount.h>
#include <fcntl.h>
#include "Utils.hh"

Utils::Utils() {
}

Utils::~Utils() {

}

int	Utils::read_mk(const std::string &filepath, std::string &key, int keysize)
{
  std::fstream file;

  file.open(filepath.c_str(), std::ios::in);
  if (file.is_open()) {
    if (getline(file, key) && key.size() != keysize)
      logger.warn << "keysize expected [" + keysize + "], got [" + key.size() + "]";
    file.close();
    return (0);
  }
  logger.info << "Cannot read keyfile " + filepath;
  return (-1);
}

std::string&	Utils::randomKey() {
  char *buffer;
  std::string *key;
  std::ifstream f("/dev/urandom");

  buffer = new char[256 + 1];
  f.read(buffer, 256);
  key = new std::string(buffer);
  return (*key);
}

bool		Utils::exist(const std::string& file)
{
  std::ifstream f(file.c_str());
  return f.good();
}

void		Utils::mkfs(std::string &path)
{
  logger.debug << "Make filesystem ext4";
  std::string cmd("mkfs.ext4 " + path);
  system(cmd.c_str());
}
