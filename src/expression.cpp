//expression.cpp
#include "expression.h"

#include <cassert>
#include <sstream>
#include <iostream>

#include "parser.h"

CreateExpression::CreateExpression(Tokenizer &tokenizer)
{
	using namespace std;
	cout << "CreateExpression(Tokenizer)" << endl;
	if (!tokenizer.hasNextWord()) {
		assert(0);
		// Throw an exception
	}
	string type = tolowercase(tokenizer.nextWord());
	if (type == "table") {
		createType = TABLE;
	} else if (type == "procedure") {
		createType = PROCEDURE;
	} else if (type == "function") {
		createType = FUNCTION;
	} else {
		assert(0);
		// Throw an exception
	}

	if (!tokenizer.hasNextWord()) {
		assert(0);
		// Throw an exception
	}

	name = tokenizer.nextWord();

}

CreateExpression::CreateExpression(const std::string &type)
{
	//this->type = type;
	std::cout << "CreateExpression()" << std::endl;
}

void CreateExpression::execute(EvaluationContext &context)
{
}
