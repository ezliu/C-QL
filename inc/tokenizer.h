//tokenizer.h

#pragma once

#include <sstream>

class Tokenizer
{
	public:
		Tokenizer(const std::string &s);
		std::string nextWord();

	private:
		std::stringstream ss;
};
