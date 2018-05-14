#include "ParticleController.h"

ParticleController::ParticleController()
{
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

void ParticleController::ChangeState(State state)
{
	currentState = state;
}

void ParticleController::DrawParticles()
{
	switch (currentState)
	{
		case Start:
		{

			ChangeState(Standard);
			break;
		}
		case Standard:
		{

			break;
		}
		case Divided:
		{


			break;
		}
		case Colliding:
		{

			break;
		}
	}
}
