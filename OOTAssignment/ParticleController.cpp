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

void ParticleController::DrawParticles()
{
	for (size_t i = 0; i < allParticles.size(); i++)
	{
		allParticles.at(i).DrawPixel();
	}
}
