//database.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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
			cout << "Exiting" << endl;
			return 0;
		} else if (input == "1") {
			EvaluationContext context;
			//string command;
			//string line;
			//while (getline(cin, line)) {
			//	command += line;
			//}
			//cin.fail() = false;
			cout << "Enter a SQL command" << endl;
			string single_command;
			getline(cin, single_command);
			try {
				//vector<auto_ptr<Expression>> exps = parseExpressions(single_command);
				//for (const auto_ptr<Expression> &exp : exps) {
				//	exp->execute(context);
				//}
				
				Tokenizer tokenizer(single_command);
				auto_ptr<Expression> exp = getExpression(tokenizer);

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
