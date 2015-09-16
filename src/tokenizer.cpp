//tokenizer.cpp

#include "tokenizer.h"

#include <iostream>
#include <cassert>

Tokenizer::Tokenizer(const std::string &s)
{
	using namespace std;
	string parsed = "";
	for (const char &ch : s) {
		if (ch == ')' ||
			ch == '(' ||
			ch == ',') {
			ss << " " << ch << " ";
		} else {
			ss << ch;
			//parsed += ch;
		}
	}
	//ss << parsed;
	cout << "Parsed version: " << ss.str() << endl;
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

std::vector<std::pair<std::string, DataType>> Tokenizer::getParameters()
{
	using namespace std;
	vector<pair<string, DataType>> params;
	string l_paren = nextWord();
	assert(l_paren == "(");
	while (true) {
		string param_name = nextWord();
		string param_type = nextWord();
		pair<string, DataType> p;
		p.first = param_name;
		p.second = stringToDatatype(param_type);
		params.push_back(p);
		string comma = nextWord();
		if (comma == ")") break;
		assert(comma == ",");
	}
	
	for (const pair<string, DataType> &p : params) {
		cout << "<" << p.first << ", " << p.second << ">" << endl;
	}
	assert(params.size() >= 1);
	return params;
}
