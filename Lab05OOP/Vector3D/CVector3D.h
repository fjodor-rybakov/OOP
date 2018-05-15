#pragma once
#include "iostream"
#include "fstream"

class CVector3D
{
public:
	// ������������ ������� ������
	CVector3D();

	// ������������ ������ � ��������� ������������
	CVector3D(double x0, double y0, double z0);

	// ���������� ����� �������
	double GetLength() const;

	// ����������� ������ (�������� ��� � ��������� �����)
	void Normalize();

	// ������ ������ � �������� ������

	// �������� ��� ���������� ������� 
	void GetCVector3D() const;

	// ��������� �������
	void ChangeVector3D(double x0, double y0, double z0);

	// ���������� �������� ��������� +
	CVector3D const operator+() const;

	// ���������� �������� ��������� -
	CVector3D const operator-() const;

	// ���������� ��������� ��������� +
	CVector3D const operator+(const CVector3D & value) const;

	// ���������� ��������� ��������� -
	CVector3D const operator-(const CVector3D & value) const;

	// ���������� ��������� +=
	CVector3D & operator+=(CVector3D const& vector);

	// ���������� ��������� -=
	CVector3D & operator-=(CVector3D const& vector);

	// ���������� ��������� *
	friend CVector3D const operator*(const CVector3D & vector, double scalar);
	friend CVector3D const operator*(double scalar, const CVector3D & vector);

	// ���������� ��������� /
	CVector3D const operator/(double scalar) const;

	// ���������� ��������� *=
	CVector3D & operator*=(double scalar);

	// ���������� ��������� /=
	CVector3D & operator/=(double scalar);

	// ���������� ��������� ==
	bool operator==(CVector3D const& other) const;

	// ���������� ��������� !=
	bool operator!=(CVector3D const& other) const;

	// ���������� ��������� <<
	friend std::ostream& operator<<(std::ostream & veiw, const CVector3D & vector);

	// ���������� ��������� >>
	friend std::istream& operator>>(std::istream & veiw, CVector3D & vector);

	// ��������� ��������� ���������� ������������ ���� ���������� ��������
	static double DotProduct(CVector3D const& v1, CVector3D const& v2);
	
	// ��������� ��������� ���������� ������������ ���� ���������� ��������
	static CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

	// ����������� ������ ����� ��������
	static CVector3D Normalize(CVector3D const& v);
	
	// � ������ ������ ������ ����� ������� ����������
	double x, y, z;

};
