//exception.h

#include <exception>
#include <string>

class Exception : public std::exception
{
	public:
		Exception(const std::string &what); // Construct an exception w/ msg
		const char* what() const noexcept; // TODO: Figure out what noexcept is 

	private:
		const std::string message; // The message returned by exception
};
