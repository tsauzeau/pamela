//
// Exception.hh for plazza in /home/thomas/cpp_plazza
//
// Made by Thomas Sauzeau
// Login   <thomas@epitech.net>
//
// Started on  Sat Apr  2 22:31:04 2016 Thomas Sauzeau
// Last update Sun Apr 24 22:42:03 2016 Cavaille Antoine
//

#ifndef EXCEPTION__HH__
# define EXCEPTION__HH__

# include <string>
# include <exception>

/** \class Exception
 * \brief Classe gérant les exceptions.
 */
class Exception : public std::exception
{
 protected:
  std::string	_what;/*!< Chaine contenant l'exception */
 public:
  Exception(std::string const &error) throw();
  virtual const char *what(void) const throw();
  virtual ~Exception(void) throw();
};

class ParamException : public Exception
{
 public:
  ParamException(std::string const &error) throw();
  virtual ~ParamException() throw();
};

#endif
