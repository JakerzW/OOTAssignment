#include "HashTable.h"

HashTable::HashTable()
{
	tableSize = 103681;
}

HashTable::~HashTable()
{
}

int HashTable::HashFunction(int key)
{
	int hashedKey;
	hashedKey = (key * (key + 3)) % 103681;
	return hashedKey;
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
