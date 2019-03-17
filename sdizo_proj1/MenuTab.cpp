#include "pch.h"
#include "MenuTab.h"



void MenuTab::run()
{
	Tab *tab = new Tab();
	string warning, path;
	Czas c;
	int choice;
	int value;
	size_t pos;
	bool found;
	while (true) {
		system("CLS");
		if (!warning.empty()) {
			cout << warning << endl;
			warning = "";
		}
		cout << "1. Dodaj na poczatek" << endl;
		cout << "2. Dodaj na wskazana pozycje" << endl;
		cout << "3. Dodaj na koniec" << endl;
		cout << "4. Usun z poczatku" << endl;
		cout << "5. Usun ze wskazanej pozycji" << endl;
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
			tab->insertAtBeginning(value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 2:
			cout << "Pozycja: ";
			cin >> pos;
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			tab->insert(pos, value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 3:
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			tab->insertAtEnd(value);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 4:
			c.start();
			tab->removeFromBeginning();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 5:
			cout << "Pozycja: ";
			cin >> pos;
			c.start();
			tab->remove(pos);
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 6:
			c.start();
			tab->removeFromEnd();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 7:
			cout << "Wartosc: ";
			cin >> value;
			c.start();
			found = tab->find(value);
			c.stop();
			if (found) {
				cout << "Podana wartosc wystepuje w tablicy" << endl;
			}
			else {
				cout << "Podana wartosc nie wystepuje w tablicy" << endl;
			}
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 8:
			c.start();
			tab->print();
			c.stop();
			cout << "Czas wykonania: " << c.result() << "ns" << endl;
			break;
		case 9:
			cout << "Sciezka do pliku: ";
			cin >> path;
			tab->readFromFile(path);
			break;
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
		if (warning.empty()) {
			system("PAUSE");
		}
	}
	delete tab;
}
