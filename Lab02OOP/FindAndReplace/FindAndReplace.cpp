#include "stdafx.h"
#include "iostream"
#include "string"
#include "FindAndReplaceStr.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Incorrect argument value." << endl;
		cout << "FindAndReplace.exe <subject-string> <search-string> <replace-string>" << endl;
		return 1;
	}

	string subjectString = argv[1];
	string searchString = argv[2];
	string replaceString = argv[3];

	cout << FindAndReplaceStr(subjectString, searchString, replaceString) << endl;

	return 0;
}

