// sdizo_proj1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "MenuTab.h"
#include "MenuLista.h"
#include "MenuHeap.h"
#include "MenuTree.h"
#include "Czas.h"

using namespace std;

void check() {
	string warning;
	int choice;
	while (true) {
		system("CLS");
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "Wybierz strukture:" << endl;
		cout << "1. Tablica" << endl;
		cout << "2. Lista" << endl;
		cout << "3. Kopiec binarny" << endl;
		cout << "4. Drzewo czerwono-czarne" << endl;
		cout << "0. Powrot" << endl;
		cout << ">";
		cin >> choice;
		switch (choice) {
		case 0:
			return;
		case 1:
			MenuTab::run();
			break;
		case 2:
			MenuLista::run();
		case 3:
			MenuHeap::run();
		case 4:
			MenuTree::run();
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
	}
}


void testTab() {
	const int s = 5;
	int sizes[s] = { 1000, 2000, 5000, 10000, 20000 };
	long avg_iBeg[s] = { 0 };
	long avg_i[s] = { 0 };
	long avg_iEnd[s] = { 0 };
	long avg_rBeg[s] = { 0 };
	long avg_r[s] = { 0 };
	long avg_rEnd[s] = { 0 };
	long avg_find[s] = { 0 };
	Czas c;
	size_t index;
	string path = "wyniki/";
	
	for (int cSize = 0; cSize < s; cSize++) {
		cout << "Rozmiar: " << sizes[cSize] << endl;
		Tab *tab = new Tab();
		vector<int> nums;
		for (int i = 0; i < sizes[cSize]; i++) {
			int r = rand();
			tab->insertAtBeginning(r);
			nums.push_back(r);
		}
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			tab->insertAtBeginning(val);
			c.stop();
			tab->removeFromBeginning();

			avg_iBeg[cSize] += c.result();
		}
		index = rand() % sizes[cSize];
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			tab->insert(index, val);
			c.stop();

			tab->removeFromBeginning();

			avg_i[cSize] += c.result();
		}
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			tab->insertAtEnd(val);
			c.stop();
			tab->removeFromEnd();

			avg_iEnd[cSize] += c.result();
		}
		for (int i = 0; i < 100; i++) {
			c.start();
			tab->removeFromBeginning();
			c.stop();
			tab->insertAtBeginning(rand());

			avg_rBeg[cSize] += c.result();
		}
		index = rand() % sizes[cSize];
		for (int i = 0; i < 100; i++) {
			
			c.start();
			tab->remove(index);
			c.stop();
			tab->insertAtBeginning(rand());

			avg_r[cSize] += c.result();
		}
		for (int i = 0; i < 100; i++) {
			c.start();
			tab->removeFromEnd();
			c.stop();
			tab->insertAtBeginning(rand());

			avg_rEnd[cSize] += c.result();
		}
		int val_to_find = nums.at(rand() % sizes[cSize]);
		for (int i = 0; i < 100; i++) {
			c.start();
			tab->find(val_to_find);
			c.stop();

			avg_find[cSize] += c.result();
		}
		delete tab;
		nums.clear();
	}
	ofstream f;
	f.open(path + string("tab_insertAtBeginning.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_iBeg[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tab_insert.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_i[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tab_insertAtEnd.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_iEnd[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tab_removeFromBeginning.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_rBeg[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tab_remove.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_r[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tab_removeFromEnd.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_rEnd[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tab_find.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_find[i] << endl;
		}
	}
	f.close();
}

void testList() {
	const int s = 5;
	const int sizes[s] = { 1000, 2000, 5000, 10000, 20000 };
	long avg_iBeg[s] = { 0 };
	long avg_i[s] = { 0 };
	long avg_iEnd[s] = { 0 };
	long avg_rBeg[s] = { 0 };
	long avg_r[s] = { 0 };
	long avg_rEnd[s] = { 0 };
	long avg_find[s] = { 0 };
	Czas c;
	int randKey;
	string path = "wyniki/";

	for (int cSize = 0; cSize < s; cSize++) {
		cout << "Rozmiar: " << sizes[cSize] << endl;
		List *list = new List();
		vector<int> nums;
		for (int i = 0; i < sizes[cSize]; i++) {
			int r = rand();
			list->insertAtBeginning(r);
			nums.push_back(r);
		}
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			list->insertAtBeginning(val);
			c.stop();
			list->removeFromBeginning();

			avg_iBeg[cSize] += c.result();
		}
		randKey = nums.at(rand() % sizes[cSize]);
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			list->insert(randKey, val);
			c.stop();

			list->remove(randKey);

			avg_i[cSize] += c.result();
		}
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			list->insertAtEnd(val);
			c.stop();
			list->removeFromEnd();

			avg_iEnd[cSize] += c.result();
		}
		
		for (int i = 0; i < 100; i++) {
			c.start();
			list->removeFromBeginning();
			c.stop();
			list->insertAtBeginning(rand());

			avg_rBeg[cSize] += c.result();
		}
		
		randKey = nums.at(rand() % sizes[cSize]);
		for (int i = 0; i < 100; i++) {

			c.start();
			list->remove(randKey);
			c.stop();
			list->insertAtBeginning(rand());

			avg_r[cSize] += c.result();
		}
		
		for (int i = 0; i < 100; i++) {
			c.start();
			list->removeFromEnd();
			c.stop();
			list->insertAtBeginning(rand());

			avg_rEnd[cSize] += c.result();
		}
		
		randKey = nums.at(rand() % sizes[cSize]);
		for (int i = 0; i < 100; i++) {
			c.start();
			list->find(randKey);
			c.stop();

			avg_find[cSize] += c.result();
		}
		delete list;
		nums.clear();
	}
	ofstream f;
	f.open(path + string("list_insertAtBeginning.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_iBeg[i] << endl;
		}
	}
	f.close();

	f.open(path + string("list_insert.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_i[i] << endl;
		}
	}
	f.close();

	f.open(path + string("list_insertAtEnd.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_iEnd[i] << endl;
		}
	}
	f.close();

	f.open(path + string("list_removeFromBeginning.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_rBeg[i] << endl;
		}
	}
	f.close();

	f.open(path + string("list_remove.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_r[i] << endl;
		}
	}
	f.close();

	f.open(path + string("list_removeFromEnd.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_rEnd[i] << endl;
		}
	}
	f.close();

	f.open(path + string("list_find.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_find[i] << endl;
		}
	}
	f.close();
}

void testHeap() {
	const int s = 5;
	int sizes[s] = { 1000, 2000, 5000, 10000, 20000 };
	long long avg_i[s] = { 0 };
	long long avg_pop[s] = { 0 };
	long long avg_r[s] = { 0 };
	long long avg_find[s] = { 0 };
	Czas c;
	int key;
	string path = "wyniki/";

	for (int cSize = 0; cSize < s; cSize++) {
		cout << "Rozmiar: " << sizes[cSize] << endl;
		Heap *heap = new Heap();
		Tab *nums = new Tab();
		for (int i = 0; i < sizes[cSize]; i++) {
			nums->insertAtBeginning(rand());
		}
		heap->keys = nums->tab;
		heap->size = sizes[cSize];
		heap->BuildFloyd();
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			heap->insert(val);
			c.stop();
			heap->remove(val);

			avg_i[cSize] += c.result();
		}
		
		for (int i = 0; i < 100; i++) {
			c.start();
			heap->pop();
			c.stop();
			heap->insert(rand());

			avg_pop[cSize] += c.result();
		}
		key = heap->keys[rand() % sizes[cSize]];
		for (int i = 0; i < 100; i++) {

			c.start();
			heap->remove(key);
			c.stop();
			heap->insert(rand());

			avg_r[cSize] += c.result();
		}

		key = heap->keys[rand() % sizes[cSize]];
		for (int i = 0; i < 100; i++) {
			c.start();
			heap->find(key);
			c.stop();

			avg_find[cSize] += c.result();
		}
		delete heap;
	}
	ofstream f;

	f.open(path + string("heap_insert.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_i[i] << endl;
		}
	}
	f.close();;

	f.open(path + string("heap_pop.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_pop[i] << endl;
		}
	}
	f.close();

	f.open(path + string("heap_remove.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_r[i] << endl;
		}
	}
	f.close();

	f.open(path + string("heap_find.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_find[i] << endl;
		}
	}
	f.close();
}

void testTree() {
	const int s = 5;
	int sizes[s] = { 1000, 2000, 5000, 10000, 20000 };
	long long avg_i[s] = { 0 };
	long long avg_r[s] = { 0 };
	long long avg_find[s] = { 0 };
	Czas c;
	int key;
	string path = "wyniki/";

	for (int cSize = 0; cSize < s; cSize++) {
		cout << "Rozmiar: " << sizes[cSize] << endl;
		Tree *tree = new Tree();
		Tab *nums = new Tab();
		for (int i = 0; i < sizes[cSize]; i++) {
			int r = rand();
			nums->insertAtBeginning(r);
			tree->insert(r);
		}
		for (int i = 0; i < 100; i++) {
			int val = rand();
			c.start();
			tree->insert(val);
			c.stop();
			tree->remove(val);

			avg_i[cSize] += c.result();
		}

		key = nums->get(rand() % sizes[cSize]);
		for (int i = 0; i < 100; i++) {

			c.start();
			tree->remove(key);
			c.stop();
			tree->insert(rand());

			avg_r[cSize] += c.result();
		}

		key = nums->get(rand() % sizes[cSize]);
		for (int i = 0; i < 100; i++) {
			c.start();
			tree->find(key);
			c.stop();

			avg_find[cSize] += c.result();
		}
	}
	ofstream f;

	f.open(path + string("tree_insert.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_i[i] << endl;
		}
	}
	f.close();;

	f.open(path + string("tree_remove.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_r[i] << endl;
		}
	}
	f.close();

	f.open(path + string("tree_find.txt"));
	if (f.is_open()) {
		for (int i = 0; i < s; i++) {
			f << avg_find[i] << endl;
		}
	}
	f.close();
}

int main()
{
	srand(time(NULL));
	string warning;
	int choice;
	while (true) {
		system("CLS");
		if (!warning.empty()) {
			cout << warning << endl;
		}
		cout << "1. Uruchom test" << endl;
		cout << "2. Sprawdzanie poprawnosci struktur" << endl;
		cout << "0. Wyjscie" << endl;
		cout << ">";
		cin >> choice;
		switch (choice) {
		case 0:
			return 0;
		case 1:
			system("CLS");
			cout << "Przeprowadzanie testow tablicy" << endl;
			testTab();
			cout << "Zakonczono" << endl;
			cout << "Przeprowadzanie testow listy" << endl;
			testList();
			cout << "Zakonczono" << endl;
			cout << "Przeprowadzanie testow kopca" << endl;
			testHeap();
			cout << "Przeprowadzanie testow drzewa czerwono-czarnego" << endl;
			testTree();
			cout << "Zakonczono wszystkie testy" << endl;
			system("PAUSE");
			break;
		case 2:
			check();
			break;
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
	}
}