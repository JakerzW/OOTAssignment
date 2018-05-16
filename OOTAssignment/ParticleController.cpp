#include "ParticleController.h"

ParticleController::ParticleController(SDL_Renderer* rend, int sWidth, int sHeight)
{
	renderer = rend;
	screenWidth = sWidth;
	screenHeight = sHeight;

	yDivide = sHeight / 2;
	xDivide1 = sWidth / 4;
	xDivide2 = sWidth / 2;
	xDivide3 = sWidth * 0.75;

	for (size_t i = 0; i < numberOfDivisions; i++)
	{
		if (i < numberOfDivisions / 2)
		{
			divisionBoundaries[i].yMin = 0;
			divisionBoundaries[i].yMax = yDivide;
		}
		else
		{
			divisionBoundaries[i].yMin = yDivide;
			divisionBoundaries[i].yMax = sHeight;
		}
	}
	for (size_t i = 0; i < numberOfDivisions; i++)
	{
		if (i == 0 || i == 4)
		{
			divisionBoundaries[i].xMin = 0;
			divisionBoundaries[i].xMax = xDivide1;
		}
		else if (i == 1 || i == 5)
		{
			divisionBoundaries[i].xMin = xDivide1;
			divisionBoundaries[i].xMax = xDivide2;
		}
		else if (i == 2 || i == 6)
		{
			divisionBoundaries[i].xMin = xDivide2;
			divisionBoundaries[i].xMax = xDivide3;
		}
		else if (i == 3 || i == 7)
		{
			divisionBoundaries[i].xMin = xDivide3;
			divisionBoundaries[i].xMax = sWidth;
		}
	}	
}

ParticleController::~ParticleController()
{

}

int ParticleController::GetParticleNum()
{
	return numberOfParticles;
}

void ParticleController::SetParticleNum(int num)
{
	numberOfParticles = num;
}

void ParticleController::IncreaseParticleNum()
{
	numberOfParticles += 1000;
}

void ParticleController::DecreaseParticleNum()
{
	numberOfParticles -= 1000;
}

void ParticleController::CreateParticles()
{
	allParticles.clear();
	for (size_t i = 0; i < numberOfParticles; i++)
	{
		Particle particle(renderer, screenWidth, screenHeight);
		allParticles.push_back(particle);
	}
	ChangeState(Standard);
}

void ParticleController::ChangeState(State state)
{
	currentState = state;
}

State ParticleController::GetState()
{
	return currentState;
}

void ParticleController::MoveParticles()
{
	for (size_t i = 0; i < allParticles.size(); i++)
	{
		allParticles.at(i).MoveParticle();
	}
}

void ParticleController::DivideParticles()
{	
	for (size_t i = 0; i < numberOfDivisions; i++)
	{
		for (size_t i = 0; i < allParticles.size(); i++)
		{
			//Check the particle against the current division
			//If it fits into the division, push the particle into the respective vector and remove from the allParticles vector
			//If it doesn't do nothing and move on
		}
	}
	//Clear the allParticles vector (check if it is empty, if not -> report error
}

void ParticleController::DrawParticles()
{
	for (size_t i = 0; i < allParticles.size(); i++)
	{
		allParticles.at(i).DrawPixel();
	}
}
