#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "map"
#include "string"
#include "sstream"
#include "Windows.h"
#include "algorithm"
#include "cctype"

using namespace std;

string StringToLower(string line)
{
	transform(line.begin(), line.end(), line.begin(), tolower);
	return line;
}

string SearchWord(string word, map<string, string> &dictionary)
{
	string result;
	bool findWord = false;
	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
	{
		if (StringToLower(it->first) == StringToLower(word))
		{
			result = it->second;
			findWord = true;
			break;
		}
	}

	if (!findWord)
	{
		cout << "Неизвестное слово “" << word << "”. Введите перевод или пустую строку для отказа." << endl;
		string translateWord;
		getline(cin, translateWord);
		if (translateWord.empty())
		{
			result = "Слово “" + word + "” проигнорировано.";
		}
		else
		{
			dictionary[word] = translateWord;
			result = "Слово “" + word + "” сохранено в словаре как “" + translateWord + "”.";
		}
	}

	return result;
}

void ReadFile(fstream &dictionaryFile, map<string, string> &dictionary)
{
	string firstWord, lastWord;
	while (getline(dictionaryFile, firstWord) && getline(dictionaryFile, lastWord))
	{
		dictionary[firstWord] = lastWord;
	}
}

void Translate(fstream &dictionaryFile, string nameDictFile, map<string, string> &dictionary)
{
	string word;
	while (true)
	{
		getline(cin, word);
		if (word == "...")
		{
			char command;
			cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.";
			cin >> command;
			if (command == 'Y' || command == 'y')
			{
				dictionaryFile.open(nameDictFile, ios_base::out);
				auto it = dictionary.begin();
				while (it != dictionary.end())
				{
					dictionaryFile << it->first << endl;
					dictionaryFile << it->second << endl;
					it++;
				}
				cout << "Изменения сохранены. До свидания." << endl;
			}
			break;
		}
		else
		{
			cout << SearchWord(word, dictionary) << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if (argc != 2)
	{
		cout << "Incorrect argument value." << endl;
		cout << "MiniDictionary.exe <dictionary file>" << endl;
		return 1;
	}

	string nameDictFile = argv[1];
	fstream dictionaryFile(nameDictFile, ios_base::in);
	map<string, string> dictionary;
	if (!dictionaryFile.is_open())
	{
		Translate(dictionaryFile, nameDictFile, dictionary);
	}
	else
	{
		ReadFile(dictionaryFile, dictionary);
		dictionaryFile.close();
		Translate(dictionaryFile, nameDictFile, dictionary);
	}
	for (auto it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}

