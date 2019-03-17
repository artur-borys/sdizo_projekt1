#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ListItem.h"

using namespace std;

class List
{
private:
	ListItem *head;
public:
	List();
	void insertAtBeginning(int value);
	void insert(int reference, int value);
	void insertAtEnd(int value);
	void removeFromBeginning();
	void remove(int key);
	void removeFromEnd();
	void clear();
	bool find(int value);
	void readFromFile(string path);
	void print();
	~List();
};

