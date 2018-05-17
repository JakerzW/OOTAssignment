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
	for (size_t i = 0; i < numberOfDivisions; i++)
	{
		dividedParticles[i].clear();
	}
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
	/*for (size_t i = 0; i < allParticles.size(); i++)
	{
		allParticles.at(i).MoveParticle();
	}*/
	if (currentState == Standard)
	{
		for (size_t i = 0; i < allParticles.size(); i++)
		{
			allParticles.at(i).MoveParticle();
		}
	}
	if (currentState == Divided || currentState == Colliding)
	{
		for (size_t i = 0; i < numberOfDivisions; i++)
		{
			for (size_t j = 0; j < dividedParticles[i].size(); j++)
			{
				dividedParticles[i][j].MoveParticle();
			}
		}
	}
}

void ParticleController::DivideParticles()
{	
	for (size_t i = 0; i < numberOfDivisions; i++)
	{
		for (size_t j = 0; j < allParticles.size(); j++)
		{
			//Check the particle against the current division
			if (divisionBoundaries[i].IsWithinBoundaries(&allParticles[j]))
			{
				//If it fits into the division, push the particle into the respective vector and remove from the allParticles vector
				dividedParticles[i].push_back(allParticles[j]);
			}
		}
	}
	ChangeState(Divided);
}

void ParticleController::SetCollidingDivision(int division)
{
	divisionBoundaries[division].SetColliding();
	ChangeState(Colliding);
}

void ParticleController::CheckCollisions()
{
	HashTable hashedParticles;
	//bool firstParticle = true;
	for (size_t i = 0; i < numberOfDivisions; i++)
	{
		if (divisionBoundaries[i].GetIsColliding())
		{
			for (size_t j = 0; j < dividedParticles[i].size(); j++)
			{
				if (hashedParticles.CheckCollision(dividedParticles[i][j].GetHashValue()) /*&& !firstParticle*/)
				{
					//delete particle
					std::cout << "Collision Detected" << std::endl;
					dividedParticles[i].erase(dividedParticles[i].begin() + j);
				}
				else
				{
					//firstParticle = false;
					hashedParticles.Insert(dividedParticles[i][j]);
				}
			}
		}
	}
}

void ParticleController::DrawDivisions()
{
	//Set line colour
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//Y divide
	SDL_RenderDrawLine(renderer, 0, yDivide, screenWidth, yDivide);
	//X divide 1
	SDL_RenderDrawLine(renderer, xDivide1, 0, xDivide1, screenHeight);
	//X divide 2
	SDL_RenderDrawLine(renderer, xDivide2, 0, xDivide2, screenHeight);
	//X divide 3
	SDL_RenderDrawLine(renderer, xDivide3, 0, xDivide3, screenHeight);
}

void ParticleController::DrawParticles()
{
	/*for (size_t i = 0; i < allParticles.size(); i++)
	{
		allParticles.at(i).DrawPixel();
	}*/
	if (currentState == Standard)
	{
		for (size_t i = 0; i < allParticles.size(); i++)
		{
			allParticles.at(i).DrawPixel();
		}
	}
	if (currentState == Divided || currentState == Colliding)
	{
		for (size_t i = 0; i < numberOfDivisions; i++)
		{
			for (size_t j = 0; j < dividedParticles[i].size(); j++)
			{
				dividedParticles[i][j].DrawPixel();
			}
		}
	}
}
