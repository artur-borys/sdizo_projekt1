#pragma once
class ListItem
{
private:
	int value;
	ListItem *next = nullptr;
public:
	ListItem();
	ListItem(int value);
	int getValue();
	void setValue(int value);
	ListItem *getNext();
	void setNext(ListItem *next);
	bool hasNext();
	~ListItem();
};

