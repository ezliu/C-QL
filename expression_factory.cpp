//expression_factory.cpp

#include <iostream>

#include "exception.h"
#include "expression_factory.h"
#include "parser.h"
#include "tokenizer.h"

std::unique_ptr<Expression> getExpression(const std::string &s)
{
	using namespace std;
	Tokenizer tokenizer(s);
	string next_token = tokenizer.nextWord();
	string expression_type = tolowercase(next_token);
	Expression *exp;
	if (expression_type == "create") {
		exp = new CreateExpression(s);
	} else {
		string error_message = "Syntax error near: " + next_token;
		error_message += "\n" + next_token + "^ " + tokenizer.rest();
		Exception e(error_message); // TODO: throw this exception properly
		throw e;
	}
	unique_ptr<Expression> x(exp);
	return x;
}
