// ParserTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Parser/CHttpUrl.h"
#include "../Parser/CUrlParsingError.h"
#include "iostream"

using namespace std;

TEST_CASE("Test paeser URL")
{
	SECTION("Check CUrlParsingError message")
	{
		cout << "Check CUrlParsingError message: " << endl;
		CUrlParsingError err("My new error");
		CHECK(err.GetErrorMessage() == "My new error");
	}

	SECTION("Create URL")
	{
		cout << "Create URL: " << endl;
		CHttpUrl url("https://habr.com/post/358564/");
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "habr.com");
		CHECK(url.GetPort() == 443);
		CHECK(url.GetDocument() == "/post/358564/");
		CHECK(url.GetURL() == "https://habr.com/post/358564/");
	}

	SECTION("Create URL with port")
	{
		cout << "Create URL with port: " << endl;
		CHttpUrl url("https://habr.com:5000/post/358564/");
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "habr.com");
		CHECK(url.GetPort() == 5000);
		CHECK(url.GetDocument() == "/post/358564/");
		CHECK(url.GetURL() == "https://habr.com:5000/post/358564/");
	}

	SECTION("Create URL with ?")
	{
		cout << "Create URL with ?: " << endl;
		CHttpUrl url("https://www.youtube.com/watch?v=d9bshi0kwBc");
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "www.youtube.com");
		CHECK(url.GetPort() == 443);
		CHECK(url.GetDocument() == "/watch?v=d9bshi0kwBc");
		CHECK(url.GetURL() == "https://www.youtube.com/watch?v=d9bshi0kwBc");
	}

	SECTION("Create constructor + 3")
	{
		cout << "Create constructor + 3:" << endl;
		CHttpUrl url("www.youtube.com", "watch?v=d9bshi0kwBc", HTTPS);
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "www.youtube.com");
		CHECK(url.GetDocument() == "/watch?v=d9bshi0kwBc");
		CHECK(url.GetPort() == 443);
		CHECK(url.GetURL() == "https://www.youtube.com/watch?v=d9bshi0kwBc");
	}

	SECTION("Create constructor + 3 HTTP")
	{
		cout << "Create constructor + 3 HTTP:" << endl;
		CHttpUrl url("www.youtube.com", "watch?v=d9bshi0kwBc", HTTP);
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "www.youtube.com");
		CHECK(url.GetDocument() == "/watch?v=d9bshi0kwBc");
		CHECK(url.GetPort() == 80);
		CHECK(url.GetURL() == "http://www.youtube.com/watch?v=d9bshi0kwBc");
	}

	SECTION("Create constructor + 4 HTTP")
	{
		cout << "Create constructor + 4 HTTP:" << endl;
		CHttpUrl url("www.youtube.com", "watch?v=d9bshi0kwBc", HTTP, 40);
		CHECK(url.GetProtocol() == HTTP);
		CHECK(url.GetDomain() == "www.youtube.com");
		CHECK(url.GetDocument() == "/watch?v=d9bshi0kwBc");
		CHECK(url.GetPort() == 40);
		CHECK(url.GetURL() == "http://www.youtube.com:40/watch?v=d9bshi0kwBc");
	}

	SECTION("Create constructor + 4 HTTPS:")
	{
		cout << "Create constructor + 4 HTTPS:" << endl;
		CHttpUrl url("www.youtube.com", "watch?v=d9bshi0kwBc", HTTPS, 568);
		CHECK(url.GetProtocol() == HTTPS);
		CHECK(url.GetDomain() == "www.youtube.com");
		CHECK(url.GetDocument() == "/watch?v=d9bshi0kwBc");
		CHECK(url.GetPort() == 568);
		CHECK(url.GetURL() == "https://www.youtube.com:568/watch?v=d9bshi0kwBc");
	}


	SECTION("Check incorrect URL")
	{
		cout << "Check incorrect URL: " << endl;
		string err;
		try
		{
			CHttpUrl url("H&?15://habr.4-post/358564/");
		}
		catch (CUrlParsingError const& e)
		{
			err = e.GetErrorMessage();
		}

		CHECK(err == "Incorrect URL");
	}

	SECTION("Check incorrect protocol")
	{
		cout << "Check incorrect protocol:" << endl;
		string err;
		try
		{
			CHttpUrl url("htt1p://www.youtube.com/watch?v=d9bshi0kwBc");
		}
		catch (CUrlParsingError const& e)
		{
			err = e.GetErrorMessage();
		}

		CHECK(err == "Incorrect protocol");
	}

	SECTION("Check incorrect domain")
	{
		cout << "Check incorrect domain:" << endl;
		string err;
		try
		{
			CHttpUrl url("www.y&outube.com", "watch?v=d9bshi0kwBc", HTTP);
		}
		catch (CUrlParsingError const& e)
		{
			err = e.GetErrorMessage();
		}

		CHECK(err == "Incorrect domain");
	}

	SECTION("Check incorrect domain")
	{
		cout << "Check incorrect domain:" << endl;
		string err;
		try
		{
			CHttpUrl url("www.youtube..com", "watch?v=d9bshi0kwBc", HTTP);
		}
		catch (CUrlParsingError const& e)
		{
			err = e.GetErrorMessage();
		}

		CHECK(err == "Incorrect domain");
	}

	SECTION("Check incorrect port")
	{
		cout << "Check incorrect port:" << endl;
		string err;
		try
		{
			CHttpUrl url("www.youtube.com", "watch?v=d9bshi0kwBc", HTTP, 0);
		}
		catch (CUrlParsingError const& e)
		{
			err = e.GetErrorMessage();
		}

		CHECK(err == "Incorrect port");
	}
}