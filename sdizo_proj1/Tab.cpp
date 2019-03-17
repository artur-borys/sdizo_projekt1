#include "pch.h"
#include "Tab.h"


Tab::Tab()
{
	size = 0;
	tab = new int[0]();
}

Tab::Tab(size_t size)
{
	tab = new int[size];
	this->size = size;
}

void Tab::insert(size_t pos, int value)
{
	// Sprawdzenie czy podana pozycja "mie�ci" si� w tablicy
	// Je�li nie, przerywamy dodawanie
	if (pos < 0 || pos > size) {
		cout << "W tablicy nie ma pozycji o indeksie: " << pos << endl;
		system("PAUSE");
		return;
	}
	// Utworzenie tablicy wi�kszej o jeden element
	int *newTab = new int[size + 1]();

	// Przypisanie podanej warto�ci do elementu na podanej pozycji
	newTab[pos] = value;

	// Skopiowanie element�w ze starej tablicy (najpierw przed nowym elementem, a potem za nim)
	for (size_t i = 0; i < pos; i++) {
		newTab[i] = tab[i];
	}
	for (size_t i = pos; i < size; i++) {
		newTab[i + 1] = tab[i];
	}

	// Zwolnienie pami�ci zajmowanej przez star� tablic� i umieszczenie adresu nowej tablicy we wska�niku
	delete []tab;
	tab = newTab;

	// Inkrementacja rozmiaru tablicy
	size++;
}

void Tab::insertAtEnd(int value)
{
	int *newTab = new int[size + 1]();
	newTab[size] = value;
	for (size_t i = 0; i < size; i++) {
		newTab[i] = tab[i];
	}

	delete []tab;
	tab = newTab;
	size++;
}

void Tab::insertAtBeginning(int value)
{
	int *newTab = new int[size + 1]();
	newTab[0] = value;
	for (size_t i = 0; i < size; i++) {
		newTab[i + 1] = tab[i];
	}

	delete []tab;
	tab = newTab;
	size++;
}

void Tab::remove(size_t pos)
{
	if (pos < 0 || pos > size) {
		cout << "Podana pozycja nie mie�ci si� w tablicy!" << endl;
		system("PAUSE");
		return;
	}
	int *newTab = new int[size - 1]();
	for (size_t i = 0; i < pos; i++) {
		newTab[i] = tab[i];
	}
	for (size_t i = pos; i < size; i++) {
		newTab[i] = tab[i + 1];
	}
	delete[]tab;
	tab = newTab;
	size--;
}

void Tab::removeFromBeginning()
{
	if (size == 0) {
		cout << "Tablica jest pusta!" << endl;
		system("PAUSE");
		return;
	}
	int *newTab = new int[size - 1]();
	for (size_t i = 0; i < size - 1; i++) {
		newTab[i] = tab[i + 1];
	}

	delete[]tab;
	tab = newTab;
	size--;
}

void Tab::removeFromEnd()
{
	if (size == 0) {
		cout << "Tablica jest pusta!" << endl;
		system("PAUSE");
		return;
	}
	int *newTab = new int[size - 1]();
	for (size_t i = 0; i < size - 1; i++) {
		newTab[i] = tab[i];
	}
	delete[]tab;
	tab = newTab;
	size--;
}

bool Tab::find(int value)
{
	for (size_t i = 0; i < size; i++) {
		if (tab[i] == value) {
			return true;
		}
	}
	return false;
}

void Tab::readFromFile(string path)
{
	size_t i = 0, newSize;
	ifstream file;
	file.open(path);
	if (file.is_open()) {
		file >> newSize;
		int *newTab = new int[newSize]();
		for (i = 0; i < newSize; i++) {
			file >> newTab[i];
		}
		delete[] tab;
		tab = newTab;
		size = newSize;
	}
	else {
		cout << "Wystapil blad podczas odczytu z pliku" << endl;
	}
}

void Tab::print()
{
	if (size == 0) {
		return;
	}
	cout << "Ilosc elementow w tablicy: " << size << endl;
	cout << "[ ";
	for (size_t i = 0; i < size - 1; i++) {
		cout << tab[i] << ", ";
	}
	cout << tab[size - 1] << " ]" << endl;
}

size_t Tab::getSize()
{
	return size;
}

int Tab::get(size_t pos)
{
	return tab[pos];
}


Tab::~Tab()
{
	delete[] tab;
}
