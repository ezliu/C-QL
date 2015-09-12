//tokenizer.h

#pragma once

#include <sstream>

class Tokenizer
{
	public:
		Tokenizer(const std::string &s);
		std::string nextWord();
		bool hasNextWord();
		std::string rest(); // Dumps rest of the tokens all together

	private:
		std::stringstream ss;
};
