#pragma once
#include <iostream>
#include <cassert>
#include "TreeItem.h"

using namespace std;

class Tree
{
public:
	string RED = "RED";
	string BLACK = "BLACK";
	TreeItem *root;
	Tree();
	void rotateLeft(TreeItem *n);
	void rotateRight(TreeItem *n);
	void insert(TreeItem *n);
	void insertRecurse(TreeItem *root, TreeItem *n);
	void insertRepairTree(TreeItem *n);
	void insertCase1(TreeItem *n);
	void insertCase2(TreeItem *n);
	void insertCase3(TreeItem *n);
	void insertCase4(TreeItem *n);
	~Tree();
};

