#include "stdafx.h"
#include "iostream"
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include "regex"

using namespace std;

CHttpUrl::CHttpUrl(std::string const& url) 
	: m_url(url)
{
	if (url.empty())
	{
		throw CUrlParsingError("Not found URL");
	}
	
	regex regex(R"(^([\w.]+)://([\w.]+)(?::([0-9]+))?(?:\/(.*))?$)", regex_constants::icase);
	smatch result;
	if (!regex_match(url, result, regex))
	{
		throw CUrlParsingError("Incorrect URL");
	}

	m_protocol = CheckProtocol(result[1]);
	m_domain = CheckDomain(result[2]);
	m_port = CheckPort(result[3]);
	m_document = CheckDocument(result[4]);
}

/*CHttpUrl::CHttpUrl(
	std::string const& domain,
	std::string const& document,
	Protocol protocol = HTTP)
{

}*/

CHttpUrl::CHttpUrl(std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
{

}

std::string CHttpUrl::GetURL() const
{
	return m_url;
}

std::string CHttpUrl::GetDomain() const
{
	return m_domain;
}

std::string CHttpUrl::GetDocument() const
{
	return m_document;
}

Protocol CHttpUrl::GetProtocol() const
{
	return m_protocol;
}

unsigned short CHttpUrl::GetPort() const
{
	return m_port;
}

Protocol CHttpUrl::CheckProtocol(std::string protocol) const
{
	transform(protocol.begin(), protocol.end(), protocol.begin(), tolower);

	if (protocol == "http")
	{
		return Protocol::HTTP;
	}

	if (protocol == "https")
	{
		return Protocol::HTTPS;
	}

	throw CUrlParsingError("Incorrect protocol");
}

std::string CHttpUrl::CheckDomain(std::string domain) const
{
	regex regex(R"(^([\w.]+)$)");
	smatch result;

	if (!regex_match(domain, result, regex))
	{
		throw CUrlParsingError("Incorrect domain");
	}

	return domain;
}

unsigned short CHttpUrl::CheckPort(std::string port) const
{
	try
	{
		unsigned short port_num = stoi(port);

		if (port_num <= 1 && port_num >= USHRT_MAX)
		{
			throw CUrlParsingError("Incorrect port");
		}

		return port_num;
	}
	catch (...) // Если не удалось преобразование
	{
		throw CUrlParsingError("Incorrect port");
	}
}

std::string CHttpUrl::CheckDocument(std::string document) const
{
	std::string doc;

	if (document.empty() || document[0] != '/')
	{
		doc = "/" + document;
	}
	else
	{
		doc = document;
	}

	return document;
}