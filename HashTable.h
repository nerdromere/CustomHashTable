#pragma once
#include <vector>
#include <iostream>

using namespace std;

class HashTable
{
private:
	struct Node {
		string name;
		long long number;
	};
	static const int TABLE_SIZE = 4177;
	vector<Node*> entries[TABLE_SIZE];
	int (*hashFunction)(string, long long);
public:
	HashTable();
	HashTable(int (*func)(string, long long));
	~HashTable();
	void Add(string name, long long number);
	string getName(string name, long long number);
	void setHashFunction(int (*func)(string, long long));
	int getSizeAtEntry(int entry);
	int getTableSize() const;
};

