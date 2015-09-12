//expression_factory.cpp

#include "expression_factory.h"
//#include "

std::unique_ptr<Expression> getExpression(const std::string &s)
{
	Expression *exp = new CreateExpression(s);
	std::unique_ptr<Expression> x(exp);
	return x;
}
