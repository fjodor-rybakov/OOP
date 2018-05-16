#pragma once
#include "string"

enum Protocol
{
	HTTP = 80,
	HTTPS = 443
};

class CHttpUrl
{
public:
	// ��������� ������� ���������� ������������� URL-�, � ������ ������ ��������
	// ���������� ���������� CUrlParsingError, ���������� ��������� �������� ������
	CHttpUrl(std::string const& url);

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	/*CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = HTTP);*/

	/* �������������� URL �� ������ ���������� ����������.
	��� �������������� ������� ���������� ����������� ����������
	std::invalid_argument
	���� ��� ��������� �� ���������� � ������� /, �� ��������� / � ����� ���������
	*/
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	// ���������� ��������� ������������� URL-�. ����, ���������� ����������� ���
	// ���������� ��������� (80 ��� http � 443 ��� https) � URL �� ������ ����������
	std::string GetURL() const;

	// ���������� �������� ���
	std::string GetDomain() const;

	/*
	���������� ��� ���������. �������:
	/
	/index.html
	/images/photo.jpg
	*/
	std::string GetDocument() const;

	// ���������� ��� ���������
	Protocol GetProtocol() const;

	// ���������� ����� �����
	unsigned short GetPort() const;

	// �������� �� ������������ ���������
	Protocol CheckProtocol(std::string protocol) const;

	// �������� �� ������������ ������
	std::string CheckDomain(std::string domain) const;

	// �������� �� ������������ �����
	unsigned short CheckPort(std::string port) const;
	
	// �������� �� ������������ ���������
	std::string CheckDocument(std::string document) const;
private:
	std::string m_url, m_domain, m_document;
	unsigned short m_port;
	Protocol m_protocol;
};
