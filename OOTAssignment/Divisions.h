#pragma once

#include "Particle.h"

class Divisions
{
	public:
		Divisions();
		~Divisions();
		bool IsWithinBoundaries(Particle* particle);
		bool GetIsColliding();
		void SetColliding(bool value);

		int xMin;
		int xMax;
		int yMin;
		int yMax;

	private:
		bool isColliding;
};