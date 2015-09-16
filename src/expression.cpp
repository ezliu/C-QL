//expression.cpp
#include "expression.h"

#include <cassert>
#include <fstream>
#include <sstream>
#include <iostream>

#include "exception.h"
#include "file_utils.h"
#include "parser.h"

// Static defs
const std::string CreateExpression::TABLE_EXTENSION = ".table";
const std::string CreateExpression::SCHEMA_EXTENSION = ".schema";
const std::string CreateExpression::TABLE_STRING = "table";
const std::string CreateExpression::PROCEDURE_STRING = "procedure";
const std::string CreateExpression::FUNCTION_STRING = "function";
const std::string CreateExpression::TABLE_DIR = "data/table/";
const std::string CreateExpression::SCHEMA_DIR = "data/schema/";

CreateExpression::CreateExpression(Tokenizer &tokenizer)
{
	using namespace std;
	cout << "CreateExpression(Tokenizer)" << endl;
	if (!tokenizer.hasNextWord()) {
		assert(0);
		// Throw an exception
	}
	string type = tolowercase(tokenizer.nextWord());
	if (type == TABLE_STRING) {
		createType = TABLE;
	} else if (type == PROCEDURE_STRING) {
		createType = PROCEDURE;
	} else if (type == FUNCTION_STRING) {
		createType = FUNCTION;
	} else {
		assert(0);
		// Throw an exception
	}

	initializeAppropriateFiles(tokenizer);
}

//CreateExpression::CreateExpression(const std::string &type)
//{
//	//this->type = type;
//	std::cout << "CreateExpression()" << std::endl;
//}

void CreateExpression::initializeAppropriateFiles(Tokenizer &tokenizer)
{
	using namespace std;

	if (!tokenizer.hasNextWord()) {
		assert(0);
		// Throw an exception
	}

	name = tokenizer.nextWord();

	try { // Try to create files
		switch (createType) {
			case TABLE: {
				fstream schema = createFile(SCHEMA_DIR + name + SCHEMA_EXTENSION);
				fstream table = createFile(TABLE_DIR + name + TABLE_EXTENSION);
				break;
			}
			case FUNCTION:
				break;
			case PROCEDURE:
				break;
			default:
				assert(0);
		};
	} catch (FileExistsException e) {
		SyntaxException s("syntax error");
		throw s;
	}
}

void CreateExpression::execute(EvaluationContext &context)
{
}
