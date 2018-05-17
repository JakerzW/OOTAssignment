#pragma once

#include <vector>
#include <string>

#include "Particle.h"

class HashTable
{
	public:
		HashTable();
		~HashTable();
		unsigned int HashFunction(int key);
		bool CheckCollision(int key);
		void Insert(Particle particle);
		void ClearTable();


	private:
		unsigned int tableSize;
		std::vector<std::vector<Particle>> table;
};
