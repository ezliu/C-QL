//tokenizer.h

#pragma once

#include <sstream>

class Tokenizer
{
	public:
		Tokenizer(const std::string &s);
		std::string nextWord();
		bool hasNextWord();

	private:
		std::stringstream ss;
};
