//============================================================================
// Name        : Drzewo_AVL.cpp
// Author      : Mariusz Perskawiec
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "przejscia.hpp"
#include "drzewo.hpp"

using namespace std;



int main() {

	AVL_TREE drzewo;	// inicjalizacja drzewa

	int wybor = 0;		// zmienne pomocnicze do obslugi menu
	int dane = 0;

	while (1) {
		cout << endl;
		cout << "1 - Wyswietl drzewo:" << endl;
		cout << "2 - Dodaj element do drzewa" << endl;
		cout << "3 - Usun element z drzewa" << endl;
		cout << "4 - Dodaj n losowych elementow do drzewa" << endl;
		cout << "5 - Prezentacja przejscia pre-order" << endl;
		cout << "6 - Prezentacja przejscia in-order" << endl;
		cout << "7 - Prezentacja przejscia post-order" << endl;
		cout << "8 - Funkcja dodajaca i usuwajaca  n losowych elementow" << endl;
		cout << "0 - Zakoncz dzialanie programu" << endl;
		cout << "Twoj wybor to: ";
		cin >> wybor;


		switch (wybor) {		// Wyswietlanie drzewa
		case 1:
			cout << " Liczba wezlow to: " << drzewo.ilosc_wezlow() << endl;
			cout << " Wysokosc drzewa to: " << drzewo.wysokosc_drzewa() << endl;
			drzewo.wyswietl_drzewo();
			break;

		case 2:					// Dodawanie nowego elementu do drzewa
			cout << "Podaj liczbe: ";
			cin >> dane;
			drzewo.dodaj_element(dane);
			break;

		case 3:					// Usowanie elementu z drzewa
			cout << "Podaj liczbe: ";
			cin >> dane;
			drzewo.usun_element(dane);
			break;

		case 4:					// Dodawanie n losowych elementow do drzewa
			cout << "Podaj ilosc elementow: ";
			cin >> dane;

			for(int i=0; i<dane; i++){
			drzewo.dodaj_element(rand());
			}
			break;

		case 5:					// Wywolanie przejscia pre_order
			pre_order(drzewo.zwroc_korzen());
			break;

		case 6:					// Wywolanie przejscia in_order
			in_order(drzewo.zwroc_korzen());
			break;

		case 7:					// Wywolanie przejscia post_order
			post_order(drzewo.zwroc_korzen());
			break;

		case 8:					// Dodawanie i usowanie n losowych elementow
		{
			cout << "Podaj ilosc elementow: ";
			cin >> dane;
			wezel  *pomocnicza;

			for(int i=0; i<dane; i++){
			drzewo.dodaj_element(rand());
			}

			for(int i=0; i<dane; i++){
				pomocnicza = drzewo.zwroc_korzen();
				drzewo.usun_element(pomocnicza->dane);
			}

		}
			break;

		case 0:					// koniec dzi³ania programu
			return 0;
			break;

		}


	}

	return 0;
}
