//expression.cpp
#include "expression.h"

#include <sstream>
#include <iostream>

CreateExpression::CreateExpression(Tokenizer &tokenizer)
{

}

CreateExpression::CreateExpression(const std::string &type)
{
	//this->type = type;
	std::cout << "CreateExpression()" << std::endl;
}

void CreateExpression::execute(EvaluationContext &context)
{
}
