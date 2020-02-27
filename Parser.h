//Parser.h, Illarion Eremenko, 1611733, February 26, 2020
#pragma once
#include "HashTable.h"
#include <iostream>
using namespace std;
class Parser
{
private:
	string filename;
	void splitNameNumber(string line, string& name, long long& number);
public:
	Parser(string filename);
	void parseFile(HashTable& ht);
};

