//Results.cpp, Illarion Eremenko, 1611733, February 26, 2020
#include "Results.h"
#include <iostream>
#include <fstream>

using namespace std;

Results::Results(string fileName)
{
	file = fileName;
}

void Results::calculateResults(HashTable& table)
{
	//find the maximum
	longestChain = table.getSizeAtEntry(0);
	for (int i = 1; i < table.getTableSize(); i++)
	{
		if (table.getSizeAtEntry(i) > longestChain)
		{
			longestChain = table.getSizeAtEntry(i);
		}
	}
	chainLength = (int*) calloc(longestChain + 1, sizeof(int));
	//populate the array
	for (int i = 0; i < table.getTableSize(); i++)
	{
		chainLength[table.getSizeAtEntry(i)]++;
	}
	//display somehow, maybe to some file
	ofstream myfile(file);
	for (int i = 0; i <= longestChain; i++)
	{
		myfile << i << "," << chainLength[i] << endl;
	}
	myfile.close();
	free(chainLength);
}

void Results::setFileName(string fileName)
{
	this->file = fileName;
}
