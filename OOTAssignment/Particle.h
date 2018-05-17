#pragma once

#include <stdlib.h>

#include "SDL.h"

class Particle
{
	public:
		Particle(SDL_Renderer* rend, int sWidth, int sHeight);
		~Particle();
		int GetPosX();
		int GetPosY();
		void SetPosition(int x, int y);
		void SetBoundaries(int xMinVal, int xMaxVal, int yMinVal, int yMaxVal);
		void SetColour(int r, int g, int b);
		int GetHashValue();
		void MoveParticle();
		void DrawPixel();

	private:
		SDL_Renderer* renderer;
		int xPos, yPos;
		int xMin, xMax, yMin, yMax;
		int screenWidth, screenHeight;
		int red, green, blue;
		int hashValue;
};


