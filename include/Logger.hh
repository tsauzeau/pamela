#ifndef LOGGER__HH__
# define LOGGER__HH__

# include <cstdio>
# include <cstdlib>
# include <iostream>
# include <ctime>
# include <vector>
# include <sys/stat.h>
# include <string>
# include <fstream>
# include <chrono>

/** \class Log
 * \brief Classe contanant les différents niveau de Log.
 *
 * DEBUG, INFO, WARN, ERROR, FATAL.
 */
class Log {
public:
  Log(unsigned int log_level, bool log_file = true);
  ~Log();

public:
  /** \class Debug
   * \brief Niveau debug
   *
   */
  class Debug {
  private:
    Log& _parent;
  public:
    Debug(Log &parent);
    ~Debug();
    Log& getParent() const;
  };

  /** \class Info
   * \brief Niveau info
   *
   */
  class Info {
  private:
    Log& _parent;
  public:
    Info(Log& parent);
    ~Info();
    Log& getParent() const;
  };

  /** \class Warn
   * \brief Niveau warn
   *
   */
  class Warn {
  private:
    Log& _parent;
  public:
    Warn(Log& parent);
    ~Warn();
    Log& getParent() const;
  };

  /** \class Error
   * \brief Niveau error
   *
   */
  class Error {
  private:
    Log& _parent;
  public:
    Error(Log& parent);
    ~Error();
    Log& getParent() const;
  };

  /** \class Fatal
   * \brief Niveau fatal
   *
   */
  class Fatal {
  private:
    Log& _parent;
  public:
    Fatal(Log& parent);
    ~Fatal();
    Log& getParent() const;
  };

  class Writer {
  private:
    std::string	_folder;
  public:
    Writer();
    ~Writer();
    Writer& operator()(const std::string&);
  };

private:
  unsigned int		_log_level; /*!< Niveau de LOG entre 0 et 4 */
  bool			_log_file; /*!< Si true, print sur le fichier de LOG "/var/log/pamela.log". */

public:
  Log::Debug		debug;
  Log::Info         info;
  Log::Warn         warn;
  Log::Error		error;
  Log::Fatal		fatal;
  Log::Writer		write;
  unsigned int get_level() const;
  bool		isLogFile() const;
  std::string getDate() const;
};

Log::Debug& operator<<(Log::Debug& deb, const std::string& txt);
Log::Info& operator<<(Log::Info& deb, const std::string& txt);
Log::Warn& operator<<(Log::Warn& deb, const std::string& txt);
Log::Error& operator<<(Log::Error& deb, const std::string& txt);
Log::Fatal& operator<<(Log::Fatal& deb, const std::string& txt);

typedef std::chrono::system_clock Clock;

extern Log logger;

#endif
