// 01.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"

using namespace std;

int main() {
	ifstream file("C://t//1.txt"); // открыли файл с текстом
	string s;
	char c, find[255];

	while (!file.eof()) {  // прочитали его и заполнили им строку
		file.get(c);
		s.push_back(c);
	}

	file.close(); // обязательно закрыли

	cout << "enter a world for find: ";
	cin >> find;

	int pos = s.find(find); // поиск

	if (pos == -1)
		cout << "not finded" << endl;
	else
		cout << "finded in " << pos << " simvol position" << endl;

	return 0;
}