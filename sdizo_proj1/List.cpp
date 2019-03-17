#include "pch.h"
#include "List.h"


List::List()
{
}

void List::insertAtBeginning(int value)
{
	ListItem *newItem = new ListItem(value);
	newItem->setNext(head);
	head = newItem;
}

void List::insert(int reference, int value)
{
	ListItem *ptr = head;
	while (ptr != nullptr) {
		if (ptr->getValue() == reference) {
			ListItem *newItem = new ListItem(value);
			newItem->setNext(ptr->getNext());
			ptr->setNext(newItem);
			return;
		}
		ptr = ptr->getNext();
	}
	insertAtBeginning(value);
}

void List::insertAtEnd(int value)
{
	if (head == nullptr) {
		insertAtBeginning(value);
	}
	else {
		ListItem *ptr = head;
		while (ptr->hasNext()) {
			ptr = ptr->getNext();
		}
		ListItem *newItem = new ListItem(value);
		ptr->setNext(newItem);
	}
}

void List::removeFromBeginning()
{
	if (head == nullptr) {
		return;
	}
	ListItem *ptr = head->getNext();
	delete head;
	head = ptr;
}

void List::remove(int key)
{
	if (head == nullptr) {
		return;
	}
	if (head->getValue() == key) {
		removeFromBeginning();
		return;
	}
	ListItem *ptr = head;
	while (ptr != nullptr) {
		if (ptr->hasNext()) {
			if (ptr->getNext()->getValue() == key) {
				ListItem *keyPtr = ptr->getNext();
				ptr->setNext(keyPtr->getNext());
				delete keyPtr;
			}
			ptr = ptr->getNext();
		}
		else {
			return;
		}
	}
}

void List::removeFromEnd()
{
	if (head == nullptr) {
		return;
	}
	if (!head->hasNext()) {
		delete head;
		head = nullptr;
		return;
	}
	ListItem *ptr = head->getNext();
	ListItem *prevPtr = head;
	while (ptr->getNext() != nullptr) {
		prevPtr = ptr;
		ptr = ptr->getNext();
	}
	delete ptr;
	prevPtr->setNext(nullptr);
}

void List::clear() {
	if (head != nullptr) {
		ListItem *ptr = head->getNext();
		while (head != nullptr) {
			delete head;
			if (ptr->hasNext()) {
				head = ptr;
				ptr = ptr->getNext();
			}
			else {
				delete ptr;
			}
		}
	}
}

bool List::find(int value)
{
	if (head == nullptr) {
		return false;
	}
	ListItem *ptr = head;
	while (ptr != nullptr) {
		if (ptr->getValue() == value) {
			return true;
		}
		ptr = ptr->getNext();
	}
	return false;
}

void List::readFromFile(string path) {
	size_t i = 0, newSize;
	int value;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		clear();
		file >> newSize;
		file >> value;
		head = new ListItem(value);
		ListItem *ptr = head;
		for (i = 1; i < newSize; i++) {
			file >> value;
			ListItem *newItem = new ListItem(value);
			ptr->setNext(newItem);
			ptr = newItem;
		}
	}
	else {
		cout << "Wystapil blad podczas odczytu z pliku" << endl;
	}
}

void List::print()
{
	if (head != nullptr) {
		ListItem *ptr = head;
		while (ptr != nullptr) {
			cout << ptr->getValue();
			if (ptr->hasNext()) {
				cout << "=>";
			}
			ptr = ptr->getNext();
		}
		cout << endl;
	}
}


List::~List()
{
	clear();
}
