#include "ParticleController.h"

ParticleController::ParticleController(SDL_Renderer* rend, int sWidth, int sHeight)
{
	renderer = rend;
	screenWidth = sWidth;
	screenHeight = sHeight;
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
}

void ParticleController::CreateParticles()
{
	for (size_t i = 0; i < numberOfParticles; i++)
	{
		Particle particle(renderer);
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

void ParticleController::DrawParticles()
{
	for (size_t i = 0; i < allParticles.size(); i++)
	{
		allParticles.at(i).DrawPixel();
	}
}
