#pragma once
#include "HashTable.h"
class Results
{
private:
	int longestChain;
	int* chainLength;
	HashTable table;
public:
	Results(HashTable& ht);
	void calculateResults();
};

