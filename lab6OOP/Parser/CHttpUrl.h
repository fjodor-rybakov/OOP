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
	// выполн€ет парсинг строкового представлени€ URL-а, в случае ошибки парсинга
	// выбрасыват исключение CUrlParsingError, содержащее текстовое описание ошибки
	CHttpUrl(std::string const& url);

	/* инициализирует URL на основе переданных параметров.
	ѕри недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	≈сли им€ документа не начинаетс€ с символа /, то добавл€ет / к имени документа
	*/
	/*CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol = HTTP);*/

	/* инициализирует URL на основе переданных параметров.
	ѕри недопустимости входных параметров выбрасывает исключение
	std::invalid_argument
	≈сли им€ документа не начинаетс€ с символа /, то добавл€ет / к имени документа
	*/
	CHttpUrl(
		std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	// возвращает строковое представление URL-а. ѕорт, €вл€ющийс€ стандартным дл€
	// выбранного протокола (80 дл€ http и 443 дл€ https) в URL не должен включатьс€
	std::string GetURL() const;

	// возвращает доменное им€
	std::string GetDomain() const;

	/*
	¬озвращает им€ документа. ѕримеры:
	/
	/index.html
	/images/photo.jpg
	*/
	std::string GetDocument() const;

	// возвращает тип протокола
	Protocol GetProtocol() const;

	// возвращает номер порта
	unsigned short GetPort() const;

	// ѕроверка на корректность протокола
	Protocol CheckProtocol(std::string protocol) const;

	// ѕроверка на корректность домена
	std::string CheckDomain(std::string domain) const;

	// ѕроверка на корректность порта
	unsigned short CheckPort(std::string port) const;
	
	// ѕроверка на корректность документа
	std::string CheckDocument(std::string document) const;
private:
	std::string m_url, m_domain, m_document;
	unsigned short m_port;
	Protocol m_protocol;
};
