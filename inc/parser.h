//parser.h

#include <string>
#include <vector>

#include "expression.h"

// Returns lowercase version of s
std::string tolowercase(const std::string &s);

// Returns a vector of ptrs to expressions based on the parsed line
// May throw an error if there is a syntax error
std::vector<std::auto_ptr<Expression>> parseExpressions(const std::string &s);

