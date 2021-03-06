//expression.h

#pragma once
#include <string>
#include <fstream>

#include "datatype.h"
#include "evaluation_context.h"
#include "tokenizer.h"

//INTERFACES
class Expression
{
	public:
		virtual void execute(EvaluationContext &context) = 0;
};

class ModifyExpression : public Expression
{
	protected:
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

		enum Type {
			TABLE,
			PROCEDURE,
			FUNCTION
		};

		Type type; 
		std::string name;      

	public:
		ModifyExpression(Tokenizer &tokenizer);
		virtual void execute(EvaluationContext &context) = 0;
};

//INSTANCES
class CreateExpression : public ModifyExpression
{
	public:
		// CONSTRUCTORS
		CreateExpression(Tokenizer &tokenizer);

		void execute(EvaluationContext &context);
	private:
		std::vector<std::pair<std::string, DataType>> params;
		void initializeAppropriateFiles();

};

class DropExpression : public ModifyExpression
{
	public:
		// CONSTRUCTORS
		DropExpression(Tokenizer &tokenizer);
		void execute(EvaluationContext &context);
};
