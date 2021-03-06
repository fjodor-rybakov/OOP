// Parser.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include "iostream"
#include "string"

using namespace std;

int main()
{
	string lineUrl;
	while (getline(cin, lineUrl))
	{
		try
		{
			CHttpUrl url(lineUrl);
			cout << "Protocol: " << url.GetStrProtocol() << endl;
			cout << "Domain: " << url.GetDomain() << endl;
			cout << "Port: " << url.GetPort() << endl;
			cout << "Document: " << url.GetDocument() << endl;
			cout << "Full URL: " << url.GetURL() << endl;
		}
		catch (CUrlParsingError const& e)
		{
			cout << e.what() << endl;
		}
	}

    return 0;
}

