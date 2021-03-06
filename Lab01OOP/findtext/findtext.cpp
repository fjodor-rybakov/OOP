// findtext.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"
#include "findtext.h"

using namespace std;

void FindLine(ifstream &input, string word) 
{
	string line;
	bool coincidence = true;
	int counter = 1;

	while (getline(input, line))
	{
		size_t position = line.find(word);

		if ((input.eof()) && coincidence)
		{
			cout << "Text not found" << endl;
			exit(1);
		}

		if (position != std::string::npos)
		{
			coincidence = false;
			cout << "Word in line: " << counter << endl;
		}

		counter++;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "There are not enough arguments.\n";
		cout << "Correct entry: findtext.exe <file name> <text to search>\n";
		return 1;
	}

	string fileName = argv[1];
	string searchLine = argv[2];
	ifstream input(fileName);

	if (input.is_open()) 
	{
		FindLine(input, searchLine);
		input.close();
	}
	else
	{
		cout << "Could not open file.";
		return 1;
	}

    return 0;
}

