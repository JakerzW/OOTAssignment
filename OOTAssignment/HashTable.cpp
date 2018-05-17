#include <vector>

#include "HashTable.h"

HashTable::HashTable()
{
	tableSize = 12007;
	table.clear();
	for (size_t i = 0; i < tableSize; i++)
	{
		std::vector<Particle> temp;
		table.push_back(temp);
	}
}

HashTable::~HashTable()
{
}

unsigned int HashTable::HashFunction(int key)
{
	//int hashedKey;
	//hashedKey = (key * (key + 3)) % 103681;
	std::string h = std::to_string(key);
	unsigned value = 0;
	int i;

	for (i = 0; i < h.length(); i++)
	{
		value ^= (value << 5) + (value >> 2) + h[i];
	}

	return value % tableSize;
}

bool HashTable::CheckCollision(int key)
{
	int hashedKey;
	hashedKey = HashFunction(key);
	for (size_t i = 0; i < table[hashedKey].size(); i++)
	{
		if (table[hashedKey].at(i).GetHashValue() == key)
		{
			return true;
		}
	}
	return false;
}

void HashTable::Insert(Particle particle)
{
	int hashedKey = HashFunction(particle.GetHashValue());
	table[hashedKey].push_back(particle);
}

void HashTable::ClearTable()
{
	table.clear();
}
