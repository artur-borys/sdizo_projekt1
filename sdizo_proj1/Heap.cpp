#include "pch.h"
#include "Heap.h"


Heap::Heap()
{
}

void Heap::insert(int key)
{
	int *newKeys = new int[size + 1]();
	for (size_t i = 0; i < size; i++) {
		newKeys[i] = keys[i];
	}
	newKeys[size] = key;
	delete[] keys;
	keys = newKeys;
	size++;
	fixUp(size - 1);
}

void Heap::remove(int key)
{	
	int index = getIndex(key);
	if (index > 0) {
		Tab *popped_keys = new Tab((size_t) index);
		int i = 0;
		while(true) {
			int current_key = keys[0];
			pop();
			if (current_key == key) {
				fixDown(0);
				break;
			}
			popped_keys->insertAtBeginning(current_key);
			i++;
		}
		for (int j = 0; j < i; j++) {
			insert(popped_keys->get(j));
		}
	}
	else if (index == 0) {
		pop();
	}
}

void Heap::pop() {
	if (size == 0) return;
	swap(&keys[0], &keys[size - 1]);
	int *newKeys = new int[size - 1]();
	for (size_t i = 0; i < size - 1; i++) {
		newKeys[i] = keys[i];
	}
	size--;
	fixDown(0);
}

bool Heap::find(int key)
{
	for (size_t i = 0; i < size; i++) {
		if (keys[i] == key) {
			return true;
		}
	}
	return false;
}

int Heap::getIndex(int key)
{
	for (size_t i = 0; i < size; i++) {
		if (keys[i] == key) {
			return i;
		}
	}
	return -1;
}

size_t Heap::leftChild(size_t pos)
{
	return 2 * pos + 1;
}

size_t Heap::rightChild(size_t pos)
{
	return 2*pos + 2;
}

size_t Heap::parent(size_t pos)
{
	return (pos - 1)/2;
}

void Heap::fixDown(size_t pos)
{
	size_t left = leftChild(pos);
	size_t right = rightChild(pos);
	size_t largest_pos = pos;
	if (left < size && keys[left] > keys[largest_pos]) {
		largest_pos = left;
	}
	if (right < size && keys[right] > keys[largest_pos]) {
		largest_pos = right;
	}

	if (largest_pos != pos) {
		swap(&keys[pos], &keys[largest_pos]);
		fixDown(largest_pos);
	}
}

void Heap::fixUp(size_t pos)
{
	if (pos == 0) return;
	size_t p = parent(pos);
	if (keys[pos] > keys[p]) {
		swap(&keys[pos], &keys[p]);
		fixUp(p);
	}
}

void Heap::swap(int * key1, int * key2)
{
	int temp = *key1;
	*key1 = *key2;
	*key2 = temp;
}

void Heap::print()
{
	if (size == 0) {
		return;
	}
	for (size_t i = 0; i < size; i++) {
		cout << keys[i] << " ";
	}
	cout << endl;
}

void Heap::clear()
{
	delete[] keys;
}

void Heap::readFromFile(string path)
{
}


Heap::~Heap()
{
	clear();
}