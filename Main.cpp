#include <iostream>
#include "HashTable.h"
#include "Parser.h"
#include "Results.h"

using namespace std;

int hash1(long long number);
int hash2(long long number);
int hash3(long long number);

int main()
{
	HashTable ht;
	ht.setHashFunction(hash3);
	Parser parser("phonebook.txt");
	parser.parseFile(ht);
	Results r(ht);
	r.calculateResults();
}

int hash1(long long number)
{
	return number % 4177;
}

int hash2(long long number)
{
	long long sum = 1;
	while (number > 0)
	{
		int num = number % 10;
		sum *= num * num;
		number /= 10;
	}
	cout << sum << endl;
	return sum % 4177;
}

int hash3(long long number)
{
	long long hash = 3;
	hash = (59 * hash + (int)(number ^ (number >> 32))) % 4177;
	return (int)hash;
}