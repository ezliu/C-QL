//expression_factory.cpp

#include <iostream>

#include "expression_factory.h"
#include "parser.h"
#include "tokenizer.h"

std::unique_ptr<Expression> getExpression(const std::string &s)
{
	using namespace std;
	Tokenizer tokenizer(s);
	string word = tolowercase(tokenizer.nextWord());
	cout << word << endl;
	Expression *exp;
	if (word == "create") {
		exp = new CreateExpression(s);
	} else {
		exception e; // TODO: throw this exception properly
		throw e;
	}
	unique_ptr<Expression> x(exp);
	return x;
}
