#include "Divisions.h"

Divisions::Divisions()
{
}

Divisions::~Divisions()
{
}

bool Divisions::IsWithinBoundaries(Particle particle)
{
	if (particle.GetPosX() > xMin && particle.GetPosX() < xMax && particle.GetPosY() > yMin && particle.GetPosY() < yMax)
	{
		return true;
	}
	else
	{
		return false;
	}
}
