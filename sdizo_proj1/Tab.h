#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tab
{
private:
	int *tab;
	size_t size;
public:
	Tab();
	Tab(size_t size);
	void insert(size_t pos, int value);
	void insertAtEnd(int value);
	void insertAtBeginning(int value);
	void remove(size_t pos);
	void removeFromBeginning();
	void removeFromEnd();
	bool find(int value);
	void readFromFile(string path);
	void print();
	size_t getSize();
	int get(size_t pos);
	~Tab();
};

