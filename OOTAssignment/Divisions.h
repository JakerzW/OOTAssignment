#pragma once

#include "Particle.h"

class Divisions
{
	public:
		Divisions();
		~Divisions();
		bool IsWithinBoundaries(Particle particle);

		int xMin;
		int xMax;
		int yMin;
		int yMax;

	private:

};