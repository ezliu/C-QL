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

//INSTANCES
class CreateExpression : public Expression
{
	enum CreateType {
		TABLE,
		PROCEDURE,
		FUNCTION
	};

	public:
		// CONSTRUCTORS
		CreateExpression(Tokenizer &tokenizer);
		CreateExpression(const std::string &type);

		void execute(EvaluationContext &context);
	private:
		CreateType createType; 
		std::string name;
};
