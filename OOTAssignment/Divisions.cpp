#include "Divisions.h"

Divisions::Divisions()
{
	isColliding = false;
}

Divisions::~Divisions()
{
}

bool Divisions::IsWithinBoundaries(Particle* particle)
{
	if (particle->GetPosX() > xMin && particle->GetPosX() < xMax && particle->GetPosY() > yMin && particle->GetPosY() < yMax)
	{
		particle->SetBoundaries(xMin, xMax, yMin, yMax);
		return true;
	}
	else
	{
		return false;
	}
}

bool Divisions::GetIsColliding()
{
	return isColliding;
}

void Divisions::SetColliding(bool value)
{
	isColliding = value;
}
