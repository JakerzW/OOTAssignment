#include "Particle.h"

Particle::Particle(SDL_Renderer* rend, int sWidth, int sHeight)
{
	//Assign the pointer to the renderer
	renderer = rend;
	
	//Set colour
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	//Set random position
	xPos = rand() % sWidth + 1;
	yPos = rand() % sHeight + 1;
}

Particle::~Particle()
{

}

int Particle::GetPosX()
{
	return xPos;
}

int Particle::GetPosY()
{
	return yPos;
}

void Particle::SetPosition(int x, int y)
{

}

void Particle::SetColour(int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void Particle::DrawPixel()
{	
	SDL_RenderDrawPoint(renderer, xPos, yPos);
}
