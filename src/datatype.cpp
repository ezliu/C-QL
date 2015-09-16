//datatype.cpp

#include "parser.h"

const static std::string INT_STR = "int";
const static std::string FLOAT_STR = "float";
const static std::string DOUBLE_STR = "double";
const static std::string CHAR_STR = "char";
const static std::string BOOL_STR = "bool";
const static std::string STRING_STR = "string";

DataType stringToDatatype(const std::string &s)
{
	using namespace std;
	string lowercase = tolowercase(s);
	if (s == INT_STR) {
		return INT;
	} else if (s == FLOAT_STR) {
		return FLOAT;
	} else if (s == DOUBLE_STR) {
		return DOUBLE;
	} else if (s == CHAR_STR) {
		return CHAR;
	} else if (s == BOOL_STR) {
		return BOOL;
	} else if (s == STRING_STR) {
		return STRING;
	} else {
		throw "Datatype not supported";
	}
}
