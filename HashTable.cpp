#include "HashTable.h"

HashTable::HashTable()
{

}

HashTable::HashTable(int(*func)(string, long long))
{
	this->hashFunction = func;
}

HashTable::~HashTable()
{
	//for (int i = 0; i < entries->size(); i++)
	//{
	//	for (int j = 0; j < entries[i].size(); j++)
	//	{
	//		delete entries[i].at[0];
	//	}
	//}
}

void HashTable::Add(string name, long long number)
{
	Node* node = new Node;
	node->name = name;
	node->number = number;
	//cout << name << number << endl;
	int index = hashFunction(name, number);
	entries[index].push_back(node);
}

string HashTable::getName(string name, long long number)
{
	int index = hashFunction(name, number);
	for (int i = 0; i < entries[index].size(); i++)
	{
		if (entries[index][i]->number == number &&
			entries[index][i]->name == name)
			return entries[index][i]->name;
	}
	return "not found";
}

void HashTable::setHashFunction(int(*func)(string, long long))
{
	this->hashFunction = func;
}

int HashTable::getSizeAtEntry(int entry)
{
	if (entry < 0 || entry > TABLE_SIZE)
		return -1;
	return entries[entry].size();
}

int HashTable::getTableSize() const
{
	return TABLE_SIZE;
}
