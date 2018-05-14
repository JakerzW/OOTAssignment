#pragma once

enum State { Start, Standard, Divided, Colliding };

class ParticleController
{
	public:
		ParticleController();
		~ParticleController();
		int GetParticleNum();
		void SetParticleNum(int num);
		void ChangeState(State state);
		void DrawParticles();

	private:
		int numberOfParticles;
		State currentState;

};