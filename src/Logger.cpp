#include <stdio.h>
#include <stdlib.h>
#include "Logger.hh"

Log::Log(unsigned int log_level, bool logf) : _log_level(log_level), _log_file(logf), debug(*new Debug(*this)),
                                                     info(*new Info(*this)), warn(*new Warn(*this)),
                                                     error(*new Error(*this)), fatal(*new Fatal(*this)),
                                                     write(*new Writer()) {
}

Log::~Log() {
}

unsigned int Log::get_level() const {
    return (_log_level);
}

bool Log::isLogFile() const {
    return (_log_file);
}

std::string Log::getDate() const {
    time_t *time;
    std::string date;

    time = new time_t;
    std::time_t result = std::time(time);
    date += std::asctime(std::localtime(&result));
    date[19] = ':';
    for (int i = 20; i != 25; i++)
        date[i] = '\0';
    auto now = Clock::now();
    auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto fraction = now - seconds;
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(fraction);
    date += std::to_string(milliseconds.count());
    return (date);
}

Log::Debug::Debug(Log &parent) : _parent(parent) {
}

Log::Debug::~Debug() {
}

Log &Log::Debug::getParent() const {
    return (_parent);
}

Log::Debug &operator<<(Log::Debug &deb, const std::string &txt) {
    if (deb.getParent().get_level() <= 0)
      {
        std::string line = "[" + deb.getParent().getDate() + "][DEBUG]: " + txt + "\n";
	if (deb.getParent().isLogFile())
	  deb.getParent().write(line);
	else
	  std::cerr << line;
      }
    return (deb);
}

Log::Info::Info(Log &parent) : _parent(parent) {
}

Log::Info::~Info() {
}

Log &Log::Info::getParent() const {
    return (_parent);
}

Log::Info &operator<<(Log::Info &deb, const std::string &txt)
{
  if (deb.getParent().get_level() <= 1)
    {
      std::string line = "[" + deb.getParent().getDate() + "][INFO]: " + txt + "\n";
	if (deb.getParent().isLogFile())
	  deb.getParent().write(line);
	else
	  std::cerr << line;
    }
  return (deb);
}

Log::Warn::Warn(Log &parent) : _parent(parent) {
}

Log::Warn::~Warn() {
}

Log &Log::Warn::getParent() const {
    return (_parent);
}

Log::Warn &operator<<(Log::Warn &deb, const std::string &txt) {
    if (deb.getParent().get_level() <= 2) {
        std::string line = "[" + deb.getParent().getDate() + "][WARN]: " + txt + "\n";
	if (deb.getParent().isLogFile())
	  deb.getParent().write(line);
	else
	  std::cerr << line;
    }
    return (deb);
}

Log::Error::Error(Log &parent) : _parent(parent) {
}

Log::Error::~Error() {
}

Log &Log::Error::getParent() const {
    return (_parent);
}

Log::Error &operator<<(Log::Error &deb, const std::string &txt) {
    if (deb.getParent().get_level() <= 3) {
        std::string line = "[" + deb.getParent().getDate() + "][ERROR]: " + txt + "\n";
	if (deb.getParent().isLogFile())
	  deb.getParent().write(line);
	else
	  std::cerr << line;
    }
    return (deb);
}

Log::Fatal::Fatal(Log &parent) : _parent(parent) {
}

Log::Fatal::~Fatal() {
}

Log &Log::Fatal::getParent() const {
    return (_parent);
}

Log::Fatal &operator<<(Log::Fatal &deb, const std::string &txt) {
    if (deb.getParent().get_level() <= 4) {
        std::string line = "[" + deb.getParent().getDate() + "][FATAL]: " + txt + "\n";
	if (deb.getParent().isLogFile())
	  deb.getParent().write(line);
	else
	  std::cerr << line;
    }
    exit(1);
    return (deb);
}


Log::Writer::Writer() {
  _folder = std::string("/var/log/");
}

Log::Writer::~Writer() {
}

Log::Writer &Log::Writer::operator()(const std::string &txt) {
    std::fstream file;
    file.open(std::string(_folder + std::string("pamela.log")).c_str(),
              std::ios::out | std::ios::app);
    if (file.is_open()) {
      file << txt << std::endl;
      file.close();
    }
    return (*this);
}
