//database.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "expression.h"
#include <sstream>

int main()
{
	using namespace std;
	string word = "hello";
	CreateExpression exp(word);
	//stringstream ss;
	//ss << "Hello, world!;" << endl;
	//while(!ss.eof()) {
	//	string word;
	//	ss >> word;
	//	cout << "Word is: ";
	//	cout << word << endl;
	//}
	//fstream file;
	//file.open("database.dat", ios::out);
	//string hello = "Hello, world!\n";
	//file << hello;
	//cout << "Hello, world!" << endl;
	//while (!file.eof()) {
	//}
	return 0;
}
