// FindAndReplaceTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../FindAndReplace/FindAndReplaceStr.h"

using namespace std;

string linee = " ";
string searche = "s";
string replacee = "p";
string expecte = " ";

string line = "p";
string searchg = "p";
string replaceg = "p";
string expect = "p";

string lineOne = "piupiupaupau";
string searchOne = "piu";
string replaceOne = "paf";
string expectOne = "pafpafpaupau";

string lineTwo = "piupiupaupau";
string searchTwo = "piu";
string replaceTwo = "s";
string expectTwo = "sspaupau";

string lineThree = "piupiupaupau";
string searchThree = "piu";
string replaceThree = "string";
string expectThree = "stringstringpaupau";

TEST_CASE("Test string")
{
	CHECK(FindAndReplaceStr(linee, searche, replacee) == expecte);
	CHECK(FindAndReplaceStr(line, searchg, replaceg) == expect);
	CHECK(FindAndReplaceStr(lineOne, searchOne, replaceOne) == expectOne);
	CHECK(FindAndReplaceStr(lineTwo, searchTwo, replaceTwo) == expectTwo);
	CHECK(FindAndReplaceStr(lineThree, searchThree, replaceThree) == expectThree);
}
