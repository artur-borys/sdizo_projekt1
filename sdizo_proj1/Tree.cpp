#include "pch.h"
#include "Tree.h"


Tree::Tree()
{
}

void Tree::rotateLeft(TreeItem * n)
{
	TreeItem *p = n->parent;
	TreeItem *nnew = n->right;
	assert(nnew != nullptr);
	n->right = nnew->left;
	nnew->left = n;
	n->parent = nnew;
	if (n->right != nullptr) {
		n->right->parent = n;
	}
	if (p != nullptr) {
		if (n == p->left) {
			p->left = nnew;
		}
		else if (n == p->right) {
			p->right = nnew;
		}
		nnew->parent = p;
	}
}

void Tree::rotateRight(TreeItem * n)
{
	TreeItem *p = n->parent;
	TreeItem *nnew = n->left;
	assert(nnew != nullptr);
	n->left = nnew->right;
	nnew->right = n;
	n->parent = nnew;
	if (n->left != nullptr) {
		n->left->parent = n;
	}
	if (p != nullptr) {
		if (n == p->left) {
			p->left = nnew;
		}
		else if (n == p->right) {
			p->right = nnew;
		}
		nnew->parent = nnew;
	}
}

void Tree::insert(TreeItem * n)
{
	insertRecurse(root, n);
	insertRepairTree(n);

	root = n;
	while (root->parent != nullptr) {
		root = root->parent;
	}
}

void Tree::insertRecurse(TreeItem *root, TreeItem * n)
{
	if (root != nullptr && n->value < root->value) {
		if (root->left != nullptr) {
			insertRecurse(root->left, n);
			return;
		}
		else {
			root->left = n;
		}
	}
	else if (root != nullptr) {
		if (root->right != nullptr) {
			insertRecurse(root->right, n);
			return;
		}
		else {
			root->right = n;
		}
	}

	n->parent = root;
	n->left = nullptr;
	n->right = nullptr;
	n->color = RED;
}

void Tree::insertRepairTree(TreeItem * n)
{
	TreeItem *p = n->parent;
	if (p == nullptr) {
		insertCase1(n);
	}
	else if (p->color == BLACK) {
		insertCase2(n);
	}
	else if (n->getUncle() != nullptr && n->getUncle()->color == RED) {
		insertCase3(n);
	}
	else {
		insertCase4(n);
	}
}

void Tree::insertCase1(TreeItem * n)
{
	if (n->parent == NULL) {
		n->color = BLACK;
	}
}

void Tree::insertCase2(TreeItem * n)
{
	return;
}

void Tree::insertCase3(TreeItem * n)
{
	n->parent->color = BLACK;
	n->getUncle()->color = BLACK;
	n->getGrandparent()->color = RED;
	insertRepairTree(n->getGrandparent());
}

void Tree::insertCase4(TreeItem * n)
{
	TreeItem *p = n->parent;
	TreeItem *g = n->getGrandparent();

	if (n == p->right && p == g->left) {
		rotateLeft(p);
		n = n->left;
	}
	else if (n == p->left && p == g->right) {
		rotateRight(p);
		n = n->right;
	}

	p = n->parent;
	g = n->getGrandparent();
	if (n == p->left) {
		rotateRight(g);
	}
	else {
		rotateLeft(g);
	}
	p->color = BLACK;
	g->color = RED;
}


Tree::~Tree()
{
}
