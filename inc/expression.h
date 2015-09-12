//expression.h

#pragma once
#include <string>
#include "evaluation_context.h"

class Expression
{
	virtual void evaluate(EvaluationContext &context) = 0;
};

class CreateExpression : public Expression
{
	public:
		CreateExpression(const std::string &type);
		void evaluate(EvaluationContext &context);
	private:
		int createType; // TODO: Deprecate this for enum
		std::string name;
};
