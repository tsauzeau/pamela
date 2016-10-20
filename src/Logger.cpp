#include <stdio.h>
#include "Logger.hh"

Log::Log(unsigned int log_level, std::string path): _log_level(log_level), _path(path), debug(*new Debug(*this)), info(*new Info(*this)), warn(*new Warn(*this)), error(*new Error(*this)), fatal(*new Fatal(*this)), write(*new Writer())
{
}

Log::~Log() {
}

unsigned int Log::get_level() const {
  return (_log_level);
}

std::string Log::get_path() const {
  return (_path);
}

std::string Log::getDate() const {
  time_t *time;
  std::string date;

  time = new time_t;
  std::time_t result = std::time(time);
  date += std::asctime(std::localtime(&result));
  date[19] = ':';
  for (int i=20; i != 25; i++)
    date[i] = '\0';
  auto now = Clock::now();
  auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
  auto fraction = now - seconds;
  auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
  date+= std::to_string(milliseconds.count());

  return (date);
}

Log::Debug::Debug(Log &parent): _parent(parent) {
}

Log::Debug::~Debug() {
}

Log& Log::Debug::getParent() const {
  return (_parent);
}

Log::Debug& operator<<(Log::Debug& deb, const std::string& txt)
{
  if (deb.getParent().get_level() <= 0)
    {
      std::string line = "[" + deb.getParent().getDate() + "][DEBUG]: " + txt + "\n";
      std::cerr << line;
    }
  return (deb);
}

Log::Info::Info(Log& parent) : _parent(parent) {
}

Log::Info::~Info() {
}

Log& Log::Info::getParent() const {
  return (_parent);
}

Log::Info& operator<<(Log::Info& deb, const std::string& txt)
{
  if (deb.getParent().get_level() <= 1)
    {
      std::string line = "[" + deb.getParent().getDate() + "][INFO]: " + txt + "\n";
      std::cerr << line;
    }
  return (deb);
}

Log::Warn::Warn(Log& parent) : _parent(parent) {
}

Log::Warn::~Warn() {
}

Log& Log::Warn::getParent() const {
  return (_parent);
}

Log::Warn& operator<<(Log::Warn& deb, const std::string& txt)
{
  if (deb.getParent().get_level() <= 2)
    {
      std::string line = "[" + deb.getParent().getDate() + "][WARN]: " + txt + "\n";
      std::cerr << line;
    }
  return (deb);
}

Log::Error::Error(Log& parent) : _parent(parent) {
}

Log::Error::~Error() {
}

Log& Log::Error::getParent() const {
  return (_parent);
}

Log::Error& operator<<(Log::Error& deb, const std::string& txt)
{
  if (deb.getParent().get_level() <= 3)
    {
      std::string line = "[" + deb.getParent().getDate() + "][ERROR]: " + txt + "\n";
      std::cerr << line;
    }
  return (deb);
}

Log::Fatal::Fatal(Log& parent) : _parent(parent) {
}

Log::Fatal::~Fatal() {
}

Log& Log::Fatal::getParent() const {
  return (_parent);
}

Log::Fatal& operator<<(Log::Fatal& deb, const std::string& txt)
{
  if (deb.getParent().get_level() <= 4)
    {
      std::string line = "[" + deb.getParent().getDate() + "][FATAL]: " + txt + "\n";
      std::cerr << line;
    }
  return (deb);
}


Log::Writer::Writer()
{
  time_t	cur;
  struct tm*	timeinfo;
  char		buff[14];

  time(&cur);
  timeinfo = localtime(&cur);
  strftime(buff, sizeof(buff), "%d%m%y_%H%M%S", timeinfo);
  buff[13] = 0;
  mkdir("logs", 0777);
  mkdir(std::string(std::string("logs/log_") + std::string(buff)).c_str(), 0777);
  _folder = std::string(std::string("logs/log_") + std::string(buff));
}

Log::Writer::~Writer() {
}

Log::Writer&	Log::Writer::operator()(size_t id, const std::string& filename, const std::vector<std::string>& res,
					const std::string& filetype)
{
  std::fstream	file;
  file.open(std::string(_folder + std::string("/order_") + std::to_string(id) + std::string(".log")).c_str(), std::ios::out | std::ios::app);
  if (file.is_open())
    {
      file << "/*" << std::endl;
      file << "** ORDER\tN°" << id << std::endl;
      file << "** FILE NAME\t[" << filename << "]" << std::endl;
      file << "** FILE TYPE\t[" << filetype << "]" << std::endl;
      file << "*/" << std::endl;
      for (size_t i = 0; i < res.size(); i++)
	file << res.at(i) << std::endl;
      file << std::endl;
      file.close();
    }
  return (*this);
}
