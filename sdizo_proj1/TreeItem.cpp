#include "pch.h"
#include "TreeItem.h"


TreeItem::TreeItem()
{
}

TreeItem::TreeItem(int value)
{
	this->value = value;
}

TreeItem* TreeItem::getSibling()
{
	if (parent == nullptr) {
		return nullptr;
	}
	else if (this == parent->left) {
		return parent->right;
	}
	else {
		return parent->left;
	}
}

TreeItem * TreeItem::getUncle()
{
	if (parent->parent == nullptr) {
		return nullptr;
	}
	return parent->getSibling();
}

TreeItem* TreeItem::getGrandparent()
{
	if (parent == nullptr) {
		return nullptr;
	}
	return parent->parent;
}

void TreeItem::print() {
	cout << "Parent: " << parent << endl;
	cout << "Value: " << value << endl;
	cout << "Left: " << left << " Right: " << right << endl;
}


TreeItem::~TreeItem()
{
}
