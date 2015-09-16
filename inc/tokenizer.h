//tokenizer.h

#pragma once

#include <sstream>
#include <vector>

#include "datatype.h"

class Tokenizer
{
	public:
		Tokenizer(const std::string &s);
		std::string nextWord();
		bool hasNextWord();

		// Dumps rest of the tokens all together
		std::string rest(); 

		// Returns a list of pairs of name to type parameters
		// If parameters are misformatted, throws an SyntaxException
		// Parameters must be formatted as: (param1 type1, param2 type2, ...)
		std::vector<std::pair<std::string, DataType>> getParameters();
	private:
		std::stringstream ss;
};
