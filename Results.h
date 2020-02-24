#pragma once
#include "HashTable.h"
class Results
{
private:
	int longestChain;
	int* chainLength;
	string file;
	HashTable table;
public:
	Results(HashTable& ht, string filename);
	void calculateResults();
	void setHashTable(HashTable& ht);
	void setFileName(string filename);
};

