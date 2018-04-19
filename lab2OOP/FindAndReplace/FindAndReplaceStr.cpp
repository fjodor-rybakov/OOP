#include "stdafx.h"
#include "FindAndReplaceStr.h"

string FindAndReplaceStr(string subjectString, string searchString, string replaceString)
{
	size_t start_pos = 0;
	while ((start_pos = subjectString.find(searchString, start_pos)) != std::string::npos)
	{
		subjectString.replace(start_pos, searchString.length(), replaceString);
		start_pos += replaceString.length();
	}

	return subjectString;
}