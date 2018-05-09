#pragma once
#include "vector"
#include "CBody.h"
#include "memory"
#include "CSphere.h"
#include "CCone.h"
#include "CParallelepiped.h"
#include "CCylinder.h"
#include "CCompound.h"

using namespace std;

class BodyController
{
public:
	shared_ptr<CSphere> AddSphere();
	shared_ptr<CParallelepiped> AddParallelepiped();
	shared_ptr<CCone> AddCone();
	shared_ptr<CCylinder> AddCylinder();
	shared_ptr<CCompound> AddCompound();
	shared_ptr<CBody> FindBodyMaxMass();
	shared_ptr<CBody> FindBodyMinMass();
	void AddShape(std::shared_ptr<CBody> elem);
	std::vector<std::shared_ptr<CBody>> GetAllShape() const;
private:
	std::vector<std::shared_ptr<CBody>> allShape;
	const int M_PW = 1000; // Плотность воды
	const double M_G = 9.8; // Ускорение свободного падения
	int radius = 0, density = 0, width = 0, height = 0, depth = 0, baseRadius = 0;
	int isCompound = 0;
};