#include "pch.h"
#include "List.h"
#include "MenuLista.h"

void MenuLista::run()
{
	List *list = new List();
	string warning, path;
	Czas c;
	int choice, value, reference;
	bool found;
	while (true) {
		system("CLS");
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "1. Dodaj na poczatek" << endl;
		cout << "2. Dodaj za wskazana pozycja" << endl;
		cout << "3. Dodaj na koniec" << endl;
		cout << "4. Usun z poczatku" << endl;
		cout << "5. Usun wskazany klucz" << endl;
		cout << "6. Usun z konca" << endl;
		cout << "7. Znajdz" << endl;
		cout << "8. Wyswietl" << endl;
		cout << "9. Wczytaj z pliku" << endl;
		cout << "0. Powrot" << endl;
		cout << ">";
		cin >> choice;
		system("CLS");
		switch (choice) {
		case 0:
			return;
		case 1:
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			list->insertAtBeginning(value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 2:
			cout << "Odnosnik: ";
			cin >> reference;
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			list->insert(reference, value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 3:
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			list->insertAtEnd(value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 4:
			c.start();
			list->removeFromBeginning();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 5:
			cout << "Klucz: ";
			cin >> value;
			c.start();
			list->remove(value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 6:
			c.start();
			list->removeFromEnd();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 7:
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			found = list->find(value);
			c.stop();
			if (found) {
				cout << "Podana wartosc wystepuje na liscie" << endl;
			}
			else {
				cout << "Podana wartosc nie wystepuje na liscie" << endl;
			}
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 8:
			c.start();
			list->print();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 9:
			cout << "Sciezka do pliku: ";
			cin >> path;
			list->readFromFile(path);
			break;
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
		if (warning.empty()) {
			system("PAUSE");
		}
	}
	delete list;
}
