#include "Particle.h"

Particle::Particle(SDL_Renderer* rend, int sWidth, int sHeight)
{
	//Assign the pointer to the renderer
	renderer = rend;
	
	//Set standard colour to white
	SetColour(255, 255, 255);

	//Set screen size to know boundary
	screenWidth = sWidth;
	screenHeight = sHeight;

	//Set movement boundaries
	xMin = 0;
	xMax = screenWidth;
	yMin = 0;
	yMax = screenHeight;

	//Set random position
	xPos = rand() % screenWidth + 1;
	yPos = rand() % screenHeight + 1;
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
	xPos = x;
	yPos = y;
}

void Particle::SetBoundaries(int xMinVal, int xMaxVal, int yMinVal, int yMaxVal)
{
	xMin = xMaxVal;
	xMax = xMaxVal;
	yMin = yMinVal;
	yMax = yMaxVal;
}

void Particle::SetColour(int r, int g, int b)
{
	red = r;
	green = g;
	blue = b;
}

void Particle::MoveParticle()
{
	bool particleMoved = false;
	while (!particleMoved)
	{
		int randDir = rand() % 4 + 1;
		switch (randDir)
		{
			case 1:
			{
				if (yPos > yMin)
				{
					yPos--;
					particleMoved = true;
					break;
				}
				else
					continue;
			}
			case 2:
			{
				if (xPos < xMax)
				{
					xPos++;
					particleMoved = true;
					break;
				}
				else
					continue;
			}
			case 3: 
			{
				if (yPos < yMax)
				{
					yPos++;
					particleMoved = true;
					break;
				}
				else
					continue;
				
			}
			case 4:
			{
				if (xPos > xMin)
				{
					xPos--;
					particleMoved = true;
					break;
				}
				else
					continue;
			}
		}
	}	
}

void Particle::DrawPixel()
{	
	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
	SDL_RenderDrawPoint(renderer, xPos, yPos);
}
