#pragma once
#include "iostream"
#include "fstream"

class CVector3D
{
public:
	// Конструирует нулевой вектор
	CVector3D();

	// Конструирует вектор с заданными координатами
	CVector3D(double x0, double y0, double z0);

	// Возвращает длину вектора
	double GetLength() const;

	// Нормализует вектор (приводит его к единичной длине)
	void Normalize();

	// Другие методы и операции класса

	// Получает все координаты вектора 
	void GetCVector3D() const;

	// Изменение вектора
	void ChangeVector3D(double x0, double y0, double z0);

	// Перегрузка унарного оператора +
	CVector3D const operator+() const;

	// Перегрузка унарного оператора -
	CVector3D const operator-() const;

	// Перегрузка бинарного оператора +
	CVector3D const operator+(const CVector3D & value) const;

	// Перегрузка бинарного оператора -
	CVector3D const operator-(const CVector3D & value) const;

	// Перегрузка оператора +=
	CVector3D & operator+=(CVector3D const& vector);

	// Перегрузка оператора -=
	CVector3D & operator-=(CVector3D const& vector);

	// Перегрузка оператора *
	friend CVector3D const operator*(const CVector3D & vector, double scalar);
	friend CVector3D const operator*(double scalar, const CVector3D & vector);

	// Перегрузка оператора /
	CVector3D const operator/(double scalar) const;

	// Перегрузка оператора *=
	CVector3D & operator*=(double scalar);

	// Перегрузка оператора /=
	CVector3D & operator/=(double scalar);

	// Перегрузка оператора ==
	bool operator==(CVector3D const& other) const;

	// Перегрузка оператора !=
	bool operator!=(CVector3D const& other) const;

	// Перегрузка оператора <<
	friend std::ostream& operator<<(std::ostream & veiw, const CVector3D & vector);

	// Перегрузка оператора >>
	friend std::istream& operator>>(std::istream & veiw, CVector3D & vector);

	// Вычисляет результат скалярного произведения двух трехмерных векторов
	static double DotProduct(CVector3D const& v1, CVector3D const& v2);
	
	// Вычисляет результат векторного произведения двух трехмерных векторов
	static CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

	// Нормализует вектор через параметр
	static CVector3D Normalize(CVector3D const& v);
	
	// В данном случае данные можно сделать публичными
	double x, y, z;

};
