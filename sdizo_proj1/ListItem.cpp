#include "pch.h"
#include "ListItem.h"


ListItem::ListItem()
{
}

ListItem::ListItem(int value)
{
	this->value = value;
}

int ListItem::getValue()
{
	return value;
}

void ListItem::setValue(int value)
{
	this->value = value;
}

ListItem * ListItem::getNext()
{
	return next;
}

void ListItem::setNext(ListItem * next)
{
	this->next = next;
}

bool ListItem::hasNext()
{
	return next != nullptr;
}


ListItem::~ListItem()
{
}
