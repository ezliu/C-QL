//tokenizer.cpp

#include "tokenizer.h"

Tokenizer::Tokenizer(const std::string &s) : ss(s)
{
}

std::string Tokenizer::nextWord()
{
	using namespace std;
	string s;
	ss >> s;
	return s;
}

bool Tokenizer::hasNextWord()
{
	return !ss.eof();
}

std::string Tokenizer::rest()
{
	using namespace std;
	string rest = "";
	while (hasNextWord()) {
		rest += " " + nextWord();
	}
	return rest;
}
