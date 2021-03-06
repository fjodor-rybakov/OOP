// crypt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "string"

using namespace std;

char Change(char ch) {
	ch = ch & 160 | ch;
	ch = ch & 66 | ch;
	ch = ch & 33 | ch;
	ch = ch & 144 | ch;
	ch = ch & 72 | ch;
	ch = ch & 20 | ch;
	ch = ch & 10 | ch;
	ch = ch & 5 | ch;

	return ch;
}

string Decryptor(string cryptLine, int key)
{
	for (unsigned int i = 0; i < cryptLine.size(); i++)
	{
		cryptLine[i] = Change(cryptLine[i]);
		cryptLine[i] = cryptLine[i] ^ key;
	}

	return cryptLine;
}

string Cryptographer(string cryptLine, int key)
{

	for (unsigned int i = 0; i < cryptLine.size(); i++) 
	{
		cryptLine[i] = cryptLine[i] ^ key;
		cryptLine[i] = Change(cryptLine[i]);
	}

	return cryptLine;
}

int StringToInt(const char* str, bool & err)
{
	char* pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));

	return param;
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "Parameters not set correctly!" << endl;
		cout << "Correct entry for crypt: crypt.exe crypt <input file> <output file> <key>" << endl;
		cout << "Correct entry for decrypt: crypt.exe decrypt <input file> <output file> <key>" << endl;
		return 1;
	}

	string option = argv[1];
	if (option == "crypt" || option == "decrypt")
	{
		string fileOneName = argv[2];
		string fileTwoName = argv[3];

		ifstream input(fileOneName);
		ofstream output(fileTwoName);

		if (!input.is_open())
		{
			cout << "Could not open file! " << fileOneName << endl;
			return 1;
		}

		if (!output.is_open())
		{
			cout << "Could not open file! " << fileTwoName << endl;
			return 1;
		}

		bool err;
		int key = StringToInt(argv[4], err);
		if (err)
		{
			cout << "Parameter key is not a number!" << endl;
			return 1;
		}

		string line;
		while (getline(input, line))
		{
			if (option == "crypt")
				output << Cryptographer(line, key) << endl;
			else
				output << Decryptor(line, key) << endl;
		}

		input.close();
		output.close();
	}
	else
	{
		cout << "Unknown operation!" << endl;
		return 1;
	}

    return 0;
}