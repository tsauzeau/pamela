#include "Exception.hh"

Exception::Exception(const std::string & msg) throw() : _what(msg)
{
}

Exception::~Exception(void) throw()
{
}

const char*Exception::what(void) const throw()
{
  return (this->_what.data());
}

ParamException::ParamException(std::string const &msg) throw(): Exception(msg)
{
}

ParamException::~ParamException() throw()
{
}
