//exception.cpp

#include "exception.h"


Exception::Exception(const std::string &what) :
   message(what)
{
}

const char* Exception::what() const noexcept
{
	return message.c_str();
}
