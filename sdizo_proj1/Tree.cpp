#include "pch.h"
#include "Tree.h"


Tree::Tree()
{
}

void Tree::rotateLeft(TreeItem * n)
{
	TreeItem *p = n->parent;
	TreeItem *nnew = n->right;
	assert(nnew != LEAF);
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
		
	}
	nnew->parent = p;
}

void Tree::rotateRight(TreeItem * n)
{
	TreeItem *p = n->parent;
	TreeItem *nnew = n->left;
	assert(nnew != LEAF);
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
	}
	nnew->parent = p;
}

void Tree::insert(int value)
{
	insert(new TreeItem(value));
}

void Tree::insert(TreeItem * n)
{
	insertRecurse(root, n);
	insertRepairTree(n);

	TreeItem *ptr = n;
	while (ptr->parent != nullptr) {
		ptr = ptr->parent;
	}
	root = ptr;
}

void Tree::insertRecurse(TreeItem *root, TreeItem * n)
{
	if (root != nullptr && n->value < root->value) {
		if (root->left != LEAF) {
			insertRecurse(root->left, n);
			return;
		}
		else {
			root->left = n;
		}
	}
	else if (root != nullptr) {
		if (root->right != LEAF) {
			insertRecurse(root->right, n);
			return;
		}
		else {
			root->right = n;
		}
	}

	n->parent = root;
	n->left = LEAF;
	n->right = LEAF;
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

void Tree::replaceNode(TreeItem * n, TreeItem * child)
{	
	child->parent = n->parent;
	if (n == root) {
		root = child;
		child = n;
		return;
	}
	if (n == n->parent->left) {
		n->parent->left = child;
	}
	else {
		n->parent->right = child;
	}
}

void Tree::remove(int value)
{
	remove(get(value));
}

void Tree::remove(TreeItem * n)
{
	if (n != nullptr) {
		if (n->left == nullptr && n->right == nullptr) {
			if (n->parent == nullptr) {
				root = nullptr;
				delete n;
			}
			else if (n->parent->left == n) {
				n->parent->left = nullptr;
				delete n;
			}
			else if (n->parent->right == n) {
				n->parent->right = nullptr;
				delete n;
			}
		}
		else {
			deleteOneChild(n);
		}
	}
}

void Tree::deleteOneChild(TreeItem *& n)
{
	TreeItem *child = isLeaf(n->right) ? n->left : n->right;
	replaceNode(n, child);
	if (n->color == BLACK) {
		if (child->color == RED) {
			child->color = BLACK;
		}
		else {
			deleteCase1(child);
		}
	}
	delete n;
}

void Tree::deleteCase1(TreeItem *& n)
{
	if (n->parent != nullptr) {
		deleteCase2(n);
	}
}

void Tree::deleteCase2(TreeItem *& n)
{
	TreeItem *s = n->getSibling();
	if (s->color == RED) {
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left) {
			rotateLeft(n->parent);
		}
		else {
			rotateRight(n->parent);
		}
	}
	deleteCase3(n);
}

void Tree::deleteCase3(TreeItem *& n)
{
	TreeItem *s = n->getSibling();
	if (n->parent->color == BLACK &&
		s->color == BLACK &&
		s->left->color == BLACK &&
		s->right->color == BLACK) {
		s->color = RED;
		deleteCase1(n->parent);
	}
	else {
		deleteCase4(n);
	}
}

void Tree::deleteCase4(TreeItem *& n)
{
	TreeItem *s = n->getSibling();

	if (n->parent->color == RED &&
		s->color == BLACK &&
		s->left->color == BLACK &&
		s->right->color == BLACK) {
		s->color = RED;
		n->parent->color = BLACK;
	}
	else {
		deleteCase5(n);
	}
}

void Tree::deleteCase5(TreeItem *& n)
{
	TreeItem *s = n->getSibling();

	if (s->color == BLACK) {
		if (n == n->parent->left &&
			s->right->color == BLACK &&
			s->left->color == RED) {
			s->color = RED;
			s->left->color = BLACK;
			rotateRight(s);
		}
		else if (n == n->parent->right &&
			s->left->color == BLACK &&
			s->right->color == RED) {
			s->color = RED;
			s->right->color = BLACK;
			rotateLeft(s);
		}
	}
	deleteCase6(n);
}

void Tree::deleteCase6(TreeItem *& n)
{
	TreeItem *s = n->getSibling();

	s->color = n->parent->color;
	n->parent->color = BLACK;

	if (n == n->parent->left) {
		s->right->color = BLACK;
		rotateLeft(n->parent);
	}
	else {
		s->left->color = BLACK;
		rotateRight(n->parent);
	}
}

void Tree::print()
{
	inOrder(root);
}

void Tree::inOrder(TreeItem * r)
{
	if (r == root && root == LEAF) return;
	if (r == nullptr) return;
	if (r->left != LEAF) inOrder(r->left);
	cout << r->value << " ";
	if (r->right != LEAF) inOrder(r->right);
}

bool Tree::find(int value)
{
	return get(value) != nullptr;
}

bool Tree::isLeaf(TreeItem * item)
{
	return item == nullptr || (item->right == nullptr && item->left == nullptr);
}

TreeItem * Tree::get(int value)
{
	return get(root, value);
}

TreeItem * Tree::get(TreeItem * n, int value)
{
	if (n == nullptr || n->value == value) {
		return n;
	}
	if (value < n->value) {
		return get(n->left, value);
	}
	return get(n->right, value);
}


Tree::~Tree()
{
	
}
