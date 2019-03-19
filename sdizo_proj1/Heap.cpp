#include "pch.h"
#include "Heap.h"
#include <cmath>


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
	/*for (int i = 0; i < size; i++) {
		cout << keys[i] << endl;
	}*/
	bool not_finished = true;
	int i, level, current_count = 1, width = 1, indent;
	/*while (true) {
		if (current_count <= size) {
			width *= 2;
			current_count += width;
		}
		else {
			break;
		}
	}
	cout << width << endl;*/
	width = 80;

	for (i = 0, level = 0; not_finished; i += pow(2, level), level++) {
		indent = width / (2 * (level + 1));
		for (int a = 0; a < indent; a++) {
			cout << " ";
		}
		int level_width = pow(2, level);
		for (int j = 0; j < level_width; j++) {
			if (i + j >= size) {
				not_finished = false;
				break;
			}
			cout << keys[i + j];
			for (int j = 0; j < width / level_width; j++) {
				cout << " ";
			}
		}
		cout << endl;
	}
}

void Heap::clear()
{
	delete[] keys;
}

void Heap::readFromFile(string path)
{
	ifstream f;
	f.open(path);
	if (f.is_open()) {
		clear();
		int num;
		f >> size;
		keys = new int[size];
		int i = 0;
		while (f >> num) {
			keys[i] = num;
			i++;
		}
		BuildFloyd();
	}
	else {
		cout << "Blad podczas odczytu z pliku!" << endl;
	}
}

void Heap::BuildFloyd()
{
	for (int i = (size - 2) / 2; i >= 0; --i) {
		fixDown(i);
	}
}


Heap::~Heap()
{
	clear();
}
