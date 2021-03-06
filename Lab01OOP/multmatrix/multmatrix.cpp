// multmatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "cstring"
#include "iomanip"

using namespace std;

vector<vector<double>> ReadMatrix(istream &input) 
{
	vector<vector<double>> matrix(3, vector<double>(3));
	char ch;
	string str;
	int row = 0, col = 0;
	double number = 0;
	while (input.get(ch))
	{
		if (ch == '\t')
		{
			number = strtod(str.c_str(), NULL);
			matrix[col][row] = number;
			row++;
			str = "";
		}
		if (ch == '\n') 
		{
			number = strtod(str.c_str(), NULL);
			matrix[col][row] = number;
			row = 0;
			col++;
			str = "";
		}
		str += ch;
	}
	number = strtod(str.c_str(), NULL);
	matrix[2][2] = number;

	return matrix;
}

vector<vector<double>> MultMatrix(const vector<vector<double>> &firstMatrix, const vector<vector<double>> &secondMatrix) 
{
	vector<vector<double>> resultMatrix(3, vector<double>(3));
	for (int r = 0; r <= 2; r++) 
		for (int c = 0; c <= 2; c++) 
			for (int i = 0; i <= 1; i++) 
				resultMatrix[r][c] += firstMatrix[r][i] * secondMatrix[i][c];

	return resultMatrix;
}

void PrintMatrix(vector<vector<double>> matrix) 
{
	for (auto &i : matrix) 
	{
		for (double j : i) cout << fixed << setprecision(3) << j << "  ";
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "There are not enough arguments." << endl;
		cout << "Correct entry: multmatrix.exe <matrix file1> <matrix file2>" << endl;
		return 1;
	}

	string firstFileMatrix = argv[1];
	string secondFileMatrix = argv[2];

	ifstream inputOne(firstFileMatrix);
	ifstream inputTwo(secondFileMatrix);

	if (inputOne.is_open())
	{
		if (inputTwo.is_open()) 
		{
			vector<vector<double>> matrixOne = ReadMatrix(inputOne);
			vector<vector<double>> matrixTwo = ReadMatrix(inputTwo);
			PrintMatrix(MultMatrix(matrixOne, matrixTwo));
		}
		else 
		{
			cout << "Could not open file: " << secondFileMatrix << endl;
			return 1;
		}
	}
	else
	{
		cout << "Could not open file: " << firstFileMatrix << endl;
		return 1;
	}

	return 0;
}