//database.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "exception.h"
#include "expression.h"
#include "parser.h"
#include "expression_factory.h"

int main()
{
	using namespace std;
	while (true) {
		cout << "Press: " << endl;
		cout << "\t1) To enter a single SQL command" << endl;
		cout << "\t2) To enter a filename to execute" << endl;
		cout << "\tq) To quit" << endl;
		string input;
		getline(cin, input);
		if (tolowercase(input) == "q")
		{
			return 0;
		} else if (input == "1") {
			string single_command;
			cout << "Enter a SQL command" << endl;
			getline(cin, single_command);
			try {
				unique_ptr<Expression> exp = getExpression(single_command);

			}
			catch (Exception e) {
				cout << e.what() << endl;

			}
		} else if (input == "2") {
		} else {
			cout << input << " is not a valid option." << endl;
		}
		cout << endl << endl;
	}
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
