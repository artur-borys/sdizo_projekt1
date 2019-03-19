#pragma once
#include <iostream>
#include <string>

using namespace std;

class TreeItem
{
public:
	string color;
	int value;
	TreeItem *parent, *left, *right;
	TreeItem();
	TreeItem(int value);
	TreeItem* getSibling();
	TreeItem* getUncle();
	TreeItem* getGrandparent();
	~TreeItem();
};

