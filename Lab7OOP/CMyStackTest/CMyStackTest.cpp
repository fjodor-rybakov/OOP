// CMyStackTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "../MainStack/CMyStack.h"

using namespace std;

TEST_CASE("Test CMyStack")
{
	SECTION("Append to top stack int")
	{
		cout << "Append to top stack int" << endl;
		CMyStack<int> myStackInt;
		myStackInt.AppendTop(125);
		myStackInt.AppendTop(254);
		myStackInt.AppendTop(431);
		CHECK(myStackInt.GetTop() == 431);
	}

	SECTION("Append to top stack string")
	{
		cout << "Append to top stack string" << endl;
		CMyStack<string> myStackString;
		myStackString.AppendTop("one");
		myStackString.AppendTop("two");
		myStackString.AppendTop("three");
		CHECK(myStackString.GetTop() == "three");
	}

	SECTION("Delete top stack string")
	{
		cout << "Delete top stack string" << endl;
		CMyStack<string> myStackString;
		myStackString.AppendTop("one");
		myStackString.AppendTop("two");
		myStackString.AppendTop("three");
		myStackString.DeleteTop();
		myStackString.DeleteTop();
		CHECK(myStackString.GetTop() == "one");
	}

	SECTION("Delete top stack string and throw")
	{
		cout << "Delete top stack string and throw" << endl;
		string ex;
		CMyStack<string> myStackString;
		myStackString.AppendTop("one");
		myStackString.AppendTop("two");
		myStackString.AppendTop("three");
		try
		{
			myStackString.DeleteTop();
			myStackString.DeleteTop();
			myStackString.DeleteTop();
			myStackString.DeleteTop();
		}
		catch (const std::exception& e)
		{
			ex = e.what();
		}
		CHECK(ex == "Stack is empty");
	}

	SECTION("Clear stack")
	{
		cout << "Clear stack" << endl;
		string ex;
		CMyStack<int> myStackInt;
		try
		{
			myStackInt.Clear();
			myStackInt.Clear();
		}
		catch (const std::exception& e)
		{
			ex = e.what();
		}

		CHECK(ex == "");
	}

	SECTION("Is empty")
	{
		cout << "Is empty" << endl;
		CMyStack<string> myStackString;
		myStackString.AppendTop("one");
		myStackString.AppendTop("two");
		myStackString.AppendTop("three");
		myStackString.DeleteTop();
		myStackString.DeleteTop();
		CHECK(myStackString.IsEmpty() == false);
		myStackString.DeleteTop();
		CHECK(myStackString.IsEmpty() == true);
	}

	SECTION("Constructor of copy")
	{
		cout << "Constructor of copy" << endl;
		CMyStack<int> myStackInt1;
		myStackInt1.AppendTop(1);
		myStackInt1.AppendTop(2);
		myStackInt1.AppendTop(3);
		myStackInt1.AppendTop(4);
		myStackInt1.AppendTop(5);
		CMyStack<int> myStackInt2(myStackInt1);
		CHECK(myStackInt1.GetTop() == 5);
		CHECK(myStackInt2.GetTop() == 5);
		myStackInt1.DeleteTop();
		myStackInt1.DeleteTop();
		myStackInt2.AppendTop(6);
		CHECK(myStackInt1.GetTop() == 3);
		CHECK(myStackInt2.GetTop() == 6);
	}

	SECTION("Overloaded constructor of copy")
	{
		cout << "Overloaded constructor of copy" << endl;
		CMyStack<int> myStackInt1;
		myStackInt1.AppendTop(1);
		myStackInt1.AppendTop(2);
		myStackInt1.AppendTop(3);
		myStackInt1.AppendTop(4);
		myStackInt1.AppendTop(5);
		CMyStack<int> myStackInt2 = myStackInt1;
		CHECK(myStackInt1.GetTop() == 5);
		CHECK(myStackInt2.GetTop() == 5);
		myStackInt1.DeleteTop();
		myStackInt1.DeleteTop();
		myStackInt2.AppendTop(6);
		CHECK(myStackInt1.GetTop() == 3);
		CHECK(myStackInt2.GetTop() == 6);

	}

	SECTION("Constructor of move")
	{
		cout << "Constructor of move" << endl;
		CMyStack<int> myStackInt1;
		myStackInt1.AppendTop(1);
		myStackInt1.AppendTop(2);
		myStackInt1.AppendTop(3);
		myStackInt1.AppendTop(4);
		myStackInt1.AppendTop(5);
		CMyStack<int> myStackInt2(move(myStackInt1));
		myStackInt2.DeleteTop();
		myStackInt2.DeleteTop();
		CHECK(myStackInt2.GetTop() == 3);

		SECTION("Check throw")
		{
			cout << "Check throw" << endl;
			string ex;
			try
			{
				myStackInt1.DeleteTop();
			}
			catch (const std::exception& e)
			{
				ex = e.what();
			}
			CHECK(ex == "Stack is empty");
		}
	}

	SECTION("Overloaded constructor of move")
	{
		cout << "Overloaded constructor of move" << endl;
		CMyStack<int> myStackInt1;
		myStackInt1.AppendTop(1);
		myStackInt1.AppendTop(2);
		myStackInt1.AppendTop(3);
		myStackInt1.AppendTop(4);
		myStackInt1.AppendTop(5);
		CMyStack<int> myStackInt2 = move(myStackInt1);
		myStackInt2.DeleteTop();
		myStackInt2.DeleteTop();
		CHECK(myStackInt2.GetTop() == 3);

		SECTION("Check throw")
		{
			cout << "Check throw" << endl;
			string ex;
			try
			{
				myStackInt1.GetTop();
			}
			catch (const std::exception& e)
			{
				ex = e.what();
			}
			CHECK(ex == "Stack is empty");
		}
	}
}