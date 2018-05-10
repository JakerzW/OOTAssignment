#pragma once

class Particle
{
	public:
		Particle();
		~Particle();
		int GetPosX();
		int GetPosY();

	private:
		int xPos;
		int yPos;
};


