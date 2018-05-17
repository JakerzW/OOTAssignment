#pragma once
#include <vector>

#include "SDL.h"
#include "Particle.h"
#include "Divisions.h"

enum State { Start, Standard, Divided, Colliding };

class ParticleController
{
	public:
		ParticleController(SDL_Renderer* rend, int sWidth, int sHeight);
		~ParticleController();
		int GetParticleNum();
		void SetParticleNum(int num);
		void IncreaseParticleNum();
		void DecreaseParticleNum();
		void CreateParticles();
		void ChangeState(State state);
		State GetState();
		void MoveParticles();
		void DivideParticles();
		void DrawDivisions();
		void DrawParticles();

		std::vector<Particle> allParticles;
		std::vector<Particle> dividedParticles[8];

	private:
		SDL_Renderer* renderer;
		int numberOfParticles;
		State currentState;
		int screenWidth, screenHeight;
		const int numberOfDivisions = 8;
		Divisions divisionBoundaries[8];
		int yDivide, xDivide1, xDivide2, xDivide3;
};