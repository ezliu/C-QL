//parser.cpp

#include "expression_factory.h"
#include "parser.h"
#include "tokenizer.h"

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

std::vector<std::auto_ptr<Expression>> parseExpressions(const std::string &s)
{
	using namespace std;
	vector<auto_ptr<Expression>> expressions;
	Tokenizer tokenizer(s);
	while (tokenizer.hasNextWord()) {
		auto_ptr<Expression> exp = getExpression(tokenizer);
		//expressions.push_back(exp);
	}
	return expressions;
}
