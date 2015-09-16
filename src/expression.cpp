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
const std::string ModifyExpression::TABLE_EXTENSION = ".table";
const std::string ModifyExpression::SCHEMA_EXTENSION = ".schema";
const std::string ModifyExpression::TABLE_STRING = "table";
const std::string ModifyExpression::PROCEDURE_STRING = "procedure";
const std::string ModifyExpression::FUNCTION_STRING = "function";
const std::string ModifyExpression::TABLE_DIR = "data/table/";
const std::string ModifyExpression::SCHEMA_DIR = "data/schema/";

ModifyExpression::ModifyExpression(Tokenizer &tokenizer)
{
	using namespace std;
	cout << "ModifyExpression(Tokenizer)" << endl;
	if (!tokenizer.hasNextWord()) {
		assert(0);
		// Throw an exception
	}
	string type = tolowercase(tokenizer.nextWord());
	if (type == TABLE_STRING) {
		type = TABLE;
	} else if (type == PROCEDURE_STRING) {
		type = PROCEDURE;
	} else if (type == FUNCTION_STRING) {
		type = FUNCTION;
	} else {
		assert(0);
		// Throw an exception
	}

	if (!tokenizer.hasNextWord()) {
		SyntaxException e("Syntax error here.");
		throw e;
		// Throw an exception
	}

	name = tokenizer.nextWord();
}

CreateExpression::CreateExpression(Tokenizer &tokenizer) :
   ModifyExpression(tokenizer)
{
}

//CreateExpression::CreateExpression(const std::string &type)
//{
//	//this->type = type;
//	std::cout << "CreateExpression()" << std::endl;
//}

void CreateExpression::initializeAppropriateFiles()
{
	using namespace std;

	try { // Try to create files
		switch (type) {
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
				break;
		};
	} catch (FileExistsException e) {
		SyntaxException s("syntax error");
		throw s;
	}
}

void CreateExpression::execute(EvaluationContext &context)
{
	using namespace std;
	cout << "execute(EvaluationContext)" << endl;
	initializeAppropriateFiles();
	cout << "Tables created :)" << endl;
}

DropExpression::DropExpression(Tokenizer &tokenizer) :
	ModifyExpression(tokenizer)
{
}

void DropExpression::execute(EvaluationContext &context)
{
	using namespace std;
	cout << "DropExpression::execute(EvaluationContext)" << endl;
	switch (type) {
		case TABLE: {
			deleteFile(TABLE_DIR + name + TABLE_EXTENSION);
			deleteFile(SCHEMA_DIR + name + SCHEMA_EXTENSION);
			break;
		}
		case FUNCTION:
			break;
		case PROCEDURE:
			break;
		default:
			assert(0);
			break;
	};
}
