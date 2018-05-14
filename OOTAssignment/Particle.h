#pragma once

class Particle
{
	public:
		Particle();
		~Particle();
		int GetPosX();
		int GetPosY();
		void SetPosition(int x, int y);
		void SetColour(int r, int g, int b);
		void DrawPixel();

	private:
		int xPos;
		int yPos;
};


