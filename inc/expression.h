//expression.h

#pragma once
#include <string>
#include <fstream>

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
		//CreateExpression(const std::string &type);

		void execute(EvaluationContext &context);
	private:
		// File extensions
		static const std::string TABLE_EXTENSION;
		static const std::string SCHEMA_EXTENSION;

		// Create types
		static const std::string TABLE_STRING;
		static const std::string PROCEDURE_STRING;
		static const std::string FUNCTION_STRING;

		// Directories
		static const std::string TABLE_DIR;
		static const std::string SCHEMA_DIR;

		void initializeAppropriateFiles(Tokenizer &tokenizer);

		CreateType createType; // Type of object being created
		std::string name;      // Name of object being created
};
