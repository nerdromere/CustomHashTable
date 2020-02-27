//Parser.h, Illarion Eremenko, 1611733, February 26, 2020
#include "Parser.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

void Parser::splitNameNumber(string line, string& name, long long& number)
{
	name = line.substr(0, line.find_first_of("\t"));
	string tempNum = line.substr(line.find_first_of("("), line.size() - line.find_first_of("("));
	//not sure which way is best to parse a phone # to long
	tempNum.erase(0, 1); // remove the "("
	tempNum.erase(3, 2); // remove the ") "
	tempNum.erase(6, 1); // remove the  "-"
	number = stoll(tempNum, nullptr, 10);
}

Parser::Parser(string filename)
{
	this->filename = filename;
}

void Parser::parseFile(HashTable& ht)
{
	ifstream myFile(filename);
	string line;
	if (myFile.is_open())
	{
		while (getline(myFile, line) && line.size() > 0)
		{
			string name;
			long long number;
			splitNameNumber(line, name, number);
			ht.Add(name, number);
		}
		myFile.close();
	}
}
