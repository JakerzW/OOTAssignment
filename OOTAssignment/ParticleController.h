#pragma once
#include <vector>

#include "SDL.h"
#include "Particle.h"

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
		void DrawParticles();

		std::vector<Particle> allParticles;

	private:
		SDL_Renderer* renderer;
		int numberOfParticles;
		State currentState;
		int screenWidth, screenHeight;
};