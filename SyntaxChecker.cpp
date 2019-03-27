/*
Scott Cummings
2317991
scummings@chapman.edu
CPSC 350 - Section 1
Assignment 3
Overview: This file runs all of the neccessary funcitons to the checking
of the delimiters
*/
#include "GenStack.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool fileExists(string fileName);
char userResponse;
int main(int argc, char** argv)
{
	GenStack<char> typeOfBracket(10);
	GenStack<int> lineNumbers(10);
	string fileName;
		if (argc > 1)
		{
			fileName = argv[1];
		}
		else
		{
			cout << "Please enter a file name in the command line." << endl;
			exit(0);
		}
		while(true)
		{
	string line;
	int lineNumber = 1;
	if (fileExists(fileName))
	{
		ifstream ifs(fileName);
		while (!ifs.eof())
		{
			getline(ifs, line);
			for (int i = 0; line[i] != '\0'; ++i)
			{
				//adds delimiter pairs and line numbers to their respective stacks
				switch (line[i])
				{
				case '{':
					typeOfBracket.push('{');
					lineNumbers.push(lineNumber);
					break;
				case '[':
					typeOfBracket.push('[');
					lineNumbers.push(lineNumber);
					break;
				case '(':
					typeOfBracket.push('(');
					lineNumbers.push(lineNumber);
					break;
				}
				//pops delimiter pairs and line numbers off their respective stacks when ends are found.
				switch (line[i])
				{
				case '}':
					if (typeOfBracket.peek() == '{')
					{
						typeOfBracket.pop();
						lineNumbers.pop();
					}
					else if (typeOfBracket.peek() == '[')
					{
						cout << "} found on line: " << lineNumber << " but ] expected." << endl;
						exit(0);
					}
					else if (typeOfBracket.peek() == '(')
					{
						cout << "} found on line: " << lineNumber << " but ) expected." << endl;
						exit(0);
					}
					else
					{
						cout << "closing } found on line " << lineNumber << "without beginning bracket {" << endl;
						exit(0);
					}
					break;
				case ']':
					if (typeOfBracket.peek() == '{')
					{
						cout << "] found on line: " << lineNumber << " but } expected." << endl;
						exit(0);
					}
					else if (typeOfBracket.peek() == '[')
					{
						typeOfBracket.pop();
						lineNumbers.pop();
					}
					else if (typeOfBracket.peek() == '(')
					{
						cout << "] found on line: " << lineNumber << " but ) expected." << endl;
						exit(0);
					}
					else
					{
						cout << "closing bracket ] found on line " << lineNumber << " without beginning bracket [." << endl;
						exit(0);
					}
					break;
				case ')':
					if (typeOfBracket.peek() == '{')
					{
						cout << ") found on line: " << lineNumber << " but } expected. " << endl;
						exit(0);
					}
					else if (typeOfBracket.peek() == '[')
					{
						cout << ") found on line: " << lineNumber << " but ] expected." << endl;
						exit(0);
					}
					else if (typeOfBracket.peek() == '(')
					{
						typeOfBracket.pop();
						lineNumbers.pop();
					}
					else
					{
						cout << "closing bracket ) found on line " << lineNumber << "without beginning bracket (." << endl;
						exit(0);
					}
				}
			}
			lineNumber++;
		}
		if (!typeOfBracket.isEmpty())
		{
			switch (typeOfBracket.peek())
			{
			case '{':
				cout << "End of file reached and closing } was not found." << endl;
				exit(0);
			case '[':
				cout << "End of file reached and closing ] was not found." << endl;
				exit(0);
			case '(':
				cout << "End of file reached and closing ) was not found." << endl;
				exit(0);
			}
		}
	}
	else
	{
		cout << "Error. File not found" << endl;
	}
	cout << "No errors found. Ya did good son." << endl;
	while(true)
	{
	cout << "Would you like to enter in another file to be analyzed?(y/n)" << endl;
	cin >> userResponse;
	if(userResponse == 'y')
	{
		cout << "What is the name of the file you wish to analyze?" << endl;
		cin >> fileName;
	}
	else if (userResponse == 'n')
	{
		cout << "Thanks for using the Syntax Checker!" << endl;
		exit(0);
	}
	else
	{
			cout << "Response not recognized. Please respond with (y/n)." << endl;
	}
	}
}

cin.get();
return 0;
}
bool fileExists(string fileName)
{
	ifstream f(fileName.c_str());
	return f.good();
}
