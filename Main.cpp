#include <iostream>
#include <string>
#include "HashTable.h"
#include "Parser.h"
#include "Results.h"

using namespace std;

int hash0(string name, long long number);
int quadraticSum(string name, long long number);
int hash3(string name, long long number);
int perfectHash(string name, long long number);
int mod(string num, int a);

int main()
{
	Parser parser("phonebook.txt");
	//create table
	HashTable ht;
	ht.setHashFunction(hash3);
	parser.parseFile(ht);
	Results r("output.csv");
	r.calculateResults(ht);
}

//
int hash0(string name, long long number)
{
	return rand() % 4177;
}

int quadraticSum(string name, long long number)
{
	long long sum = 1;
	int num = 0;
	int iter = 1;
	while (number > 0)
	{
		int num = number % 10;
		sum += num * num * iter++;
		//sum += num * num;
		number /= 10;
	}
	for (char c : name)
	{
		sum += c * c * iter++;
	}
	//cout << sum << endl;
	return sum % 4177;
}

int hash3(string name, long long number)
{
	hash<string> nameHash;
	size_t num1 = nameHash(name);
	hash<long long> numberHash;
	size_t num2 = numberHash(number);
	return (num1 * num2) % 4177;
}

int perfectHash(string name, long long number)
{
	//create the random array of digits (has to be used to "get" the phone number)
	int randomArray[64] =
	{ 1, 7, 4, 0, 9, 4, 8, 8,
	  2, 4, 5, 5, 1, 7, 1, 1,
	  5, 2, 7, 6, 1, 4, 2, 3,
	  2, 2, 1, 6, 8, 5, 7, 6,
	  1, 8, 9, 2, 7, 9, 5, 4,
	  3, 1, 2, 3, 3, 4, 1, 1,
	  3, 8, 7, 4, 2, 7, 7, 9,
	  3, 1, 9, 8, 6, 5, 0, 2 };
	int counter = 0;
	string buildingHash = "";
	do
	{
		//if it's odd and there's a 1 on the end
		if (number % 2 == 1)
		{
			buildingHash.append(to_string(randomArray[counter]));
		}
		counter++;
		number = number >> 1; //shift to the right one
	} while (number > 0);
	//cout << buildingHash << endl;
	for (char c : name)
	{
		buildingHash.append(to_string(randomArray[c % 64]));
	}
	return mod(buildingHash, 4177);
}

//Credit to: https://www.geeksforgeeks.org/how-to-compute-mod-of-a-big-number/
int mod(string num, int a)
{
	// Initialize result 
	int res = 0;

	// One by one process all digits of 'num' 
	for (int i = 0; i < num.length(); i++)
		res = (res * 10 + (int)num[i] - '0') % a;

	return res;
}