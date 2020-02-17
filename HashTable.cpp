#include "HashTable.h"

HashTable::HashTable()
{

}

HashTable::HashTable(int(*func)(long long))
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
	cout << name << number << endl;
	int index = hashFunction(number);
	entries[index].push_back(node);
}

void HashTable::setHashFunction(int(*func)(long long))
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
