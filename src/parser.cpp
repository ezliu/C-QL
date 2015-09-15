//parser.cpp

#include "parser.h"

std::string tolowercase(const std::string &s)
{
	std::string ret = "";
	for (char ch : s) {
		if (ch >= 'A' && ch <= 'Z') {
			ret += ch - 'A' + 'a';
		} else {
			ret += ch;
		}
	}
	return ret;
}
