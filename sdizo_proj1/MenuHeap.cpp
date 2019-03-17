#include "pch.h"
#include "MenuHeap.h"



void MenuHeap::run()
{
	Heap *heap = new Heap();
	string warning, path;
	Czas c;
	int choice;
	int key;
	bool found;
	while (true) {
		system("CLS");
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "1. Dodaj" << endl;
		cout << "2. Usun" << endl;
		cout << "3. Znajdz" << endl;
		cout << "4. Wyswietl" << endl;
		cout << "5. Wczytaj z pliku" << endl;
		cout << "0. Powrot" << endl;
		cout << ">";
		cin >> choice;
		system("CLS");
		switch (choice) {
		case 0:
			return;
		case 1:
			cout << "Wartosc: ";
			cin >> key;
			c.start();
			heap->insert(key);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 2:
			cout << "Wartosc: ";
			cin >> key;
			c.start();
			heap->remove(key);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 3:
			cout << "Wartosc: ";
			cin >> key;
			c.start();
			found = heap->find(key);
			c.stop();
			if (found) {
				cout << "Podana wartosc wystepuje w tablicy" << endl;
			}
			else {
				cout << "Podana wartosc nie wystepuje w tablicy" << endl;
			}
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 4:
			c.start();
			heap->print();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 5:
			cout << "Sciezka do pliku: ";
			cin >> path;
			heap->readFromFile(path);
			break;
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
		if (warning.empty()) {
			system("PAUSE");
		}
	}
	delete heap;
}
