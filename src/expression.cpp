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
	string type_str = tolowercase(tokenizer.nextWord());
	if (type_str == TABLE_STRING) {
		type = TABLE;
	} else if (type_str == PROCEDURE_STRING) {
		type = PROCEDURE;
	} else if (type_str == FUNCTION_STRING) {
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
    ModifyExpression(tokenizer),
	params(tokenizer.getParameters())
{
}

void CreateExpression::initializeAppropriateFiles()
{
	using namespace std;

	try { // Try to create files
		switch (type) {
			case TABLE: {
				fstream schema = createFile(SCHEMA_DIR + name + SCHEMA_EXTENSION);
				fstream table = createFile(TABLE_DIR + name + TABLE_EXTENSION);
				schema << "( ";
				schema << params[0].first << " " << params[0].second;
				for (size_t i = 1; i < params.size(); i++) {
					schema << ", " << params[i].first << " " << params[i].second;
				}
				schema << " )";
				break;
			}
			case FUNCTION:
				break;
			case PROCEDURE:
				break;
			default:
				SyntaxException s("Type Error");
				throw s;
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
	cout << "CreateExpression::execute(EvaluationContext)" << endl;
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
			cout << "Table dropped." << endl;
			break;
		}
		case FUNCTION:
			break;
		case PROCEDURE:
			break;
		default:
			//assert(0);
			break;
	};
}
