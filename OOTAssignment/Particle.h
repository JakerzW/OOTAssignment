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
		void SetColour(int r, int g, int b);
		void MoveParticle();
		void DrawPixel();

	private:
		SDL_Renderer* renderer;
		int xPos, yPos;
		int screenWidth, screenHeight;
		int red, green, blue;
};


