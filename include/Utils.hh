#ifndef UTILS_HH_
# define UTILS_HH_

class Utils {
public:
  Utils();
  ~Utils();
  int read_mk(const std::string&, std::string&, int);
  std::string& randomKey();
  bool exist(const std::string &);
  void mkfs(std::string &);
};

#endif /* !UTILS_HH_ */
