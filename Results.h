#pragma once
#include "HashTable.h"
class Results
{
private:
	int longestChain;
	int* chainLength;
	string file;
public:
	Results(string filename);
	void calculateResults(HashTable& table);
	void setFileName(string filename);
};

