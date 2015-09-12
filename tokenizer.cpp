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
