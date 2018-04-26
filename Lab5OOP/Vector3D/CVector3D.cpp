#include "stdafx.h"
#include "CVector3D.h"
#include "iostream"
#include <float.h>

CVector3D::CVector3D() : x(0), y(0), z(0)
{	
}

CVector3D::CVector3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0)
{
}

double CVector3D::GetLength() const
{
	return (round(sqrt(x * x + y * y + z * z) * 1000) / 1000);
}

void CVector3D::Normalize()
{
	double halfLength = round(1 / GetLength() * 1000) / 1000;
	x = x * halfLength;
	y = y * halfLength;
	z = z * halfLength;
}

void CVector3D::ChangeVector3D(double x0, double y0, double z0)
{
	x = x0;
	y = y0;
	z = z0;
}

void CVector3D::GetCVector3D() const
{
	std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
}

CVector3D const CVector3D::operator+() const
{
	return *this;
}

CVector3D const CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D const CVector3D::operator+(const CVector3D & value) const
{
	return CVector3D(this->x + value.x, this->y + value.y, this->z + value.z);
}

CVector3D const CVector3D::operator-(const CVector3D & value) const
{
	return CVector3D(this->x - value.x, this->y - value.y, this->z - value.z);
}

CVector3D & CVector3D::operator+=(CVector3D const& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;

	return *this;
}

CVector3D & CVector3D::operator-=(CVector3D const& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;

	return *this;
}

CVector3D const operator *(const CVector3D & vector, double scalar)
{
	return CVector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

CVector3D const operator*(double scalar, const CVector3D & vector)
{
	return CVector3D(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

CVector3D const CVector3D::operator/(double scalar) const
{
	return CVector3D(x / scalar, y / scalar, z / scalar);
}

CVector3D & CVector3D::operator*=(double scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;

	return *this;
}

CVector3D & CVector3D::operator/=(double scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;

	return *this;
}

bool CVector3D::operator==(CVector3D const& other) const
{
	return (x == other.x) && (y == other.y) && (z == other.z);
}

bool CVector3D::operator!=(CVector3D const& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream & veiw, const CVector3D & vector)
{
	veiw << "[ " << vector.x << ", " << vector.y << ", " << vector.z << " ]";
	return veiw;
}

std::istream& operator>>(std::istream & veiw, CVector3D & vector)
{
	std::cout << "Please enter Vector3D.\nx: ";
	std::cin >> vector.x;
	std::cout << "y: ";
	std::cin >> vector.y;
	std::cout << "z: ";
	std::cin >> vector.z;

	return veiw;
}

double CVector3D::DotProduct(CVector3D const& v1, CVector3D const& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

CVector3D CVector3D::CrossProduct(CVector3D const& v1, CVector3D const& v2)
{
	return CVector3D(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.z);
}