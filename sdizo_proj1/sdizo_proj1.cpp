// sdizo_proj1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "MenuTab.h"
#include "MenuLista.h"
#include "MenuHeap.h"

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
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
	}
}

int main()
{
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
			break;
		case 2:
			check();
			break;
		default:
			warning = "Musisz wybrac opcje z listy!";
		}
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
