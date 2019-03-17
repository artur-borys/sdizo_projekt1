#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Tab.h"

using namespace std;

class Heap
{
private:
	int *keys;
	size_t size = 0;
public:
	Heap();
	void insert(int key);
	void remove(int key);
	void pop();
	bool find(int key);
	int getIndex(int key);
	size_t leftChild(size_t pos);
	size_t rightChild(size_t pos);
	size_t parent(size_t pos);
	void fixDown(size_t pos);
	void fixUp(size_t pos);
	void swap(int *key1, int *key2);
	void print();
	void clear();
	void readFromFile(string path);
	~Heap();
};

