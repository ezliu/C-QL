//expression.h

#pragma once
#include <string>

#include "evaluation_context.h"
#include "tokenizer.h"

//INTERFACE
class Expression
{
	public:
		virtual void execute(EvaluationContext &context) = 0;
};

class CreateExpression : public Expression
{
	public:
		// CONSTRUCTORS
		CreateExpression(Tokenizer &tokenizer);
		CreateExpression(const std::string &type);

		void execute(EvaluationContext &context);
	private:
		int createType; // TODO: Deprecate this for enum
		std::string name;
};
