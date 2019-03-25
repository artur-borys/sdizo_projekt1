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
	TreeItem *LEAF = new TreeItem();
	TreeItem *root;
	Tree();
	void rotateLeft(TreeItem *n);
	void rotateRight(TreeItem *n);
	void insert(int value);
	void insert(TreeItem *n);
	void insertRecurse(TreeItem *root, TreeItem *n);
	void insertRepairTree(TreeItem *n);
	void insertCase1(TreeItem *n);
	void insertCase2(TreeItem *n);
	void insertCase3(TreeItem *n);
	void insertCase4(TreeItem *n);
	void replaceNode(TreeItem *n, TreeItem *child);
	void remove(int value);
	void remove(TreeItem *n);
	void deleteOneChild(TreeItem *&n);
	void deleteCase1(TreeItem *&n);
	void deleteCase2(TreeItem *&n);
	void deleteCase3(TreeItem *&n);
	void deleteCase4(TreeItem *&n);
	void deleteCase5(TreeItem *&n);
	void deleteCase6(TreeItem *&n);
	void print();
	void inOrder(TreeItem *r);
	bool find(int value);
	bool isLeaf(TreeItem *item);
	TreeItem *get(int value);
	TreeItem *get(TreeItem *n, int value);
	~Tree();
};

