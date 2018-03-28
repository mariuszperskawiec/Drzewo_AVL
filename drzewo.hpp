/*
 * drzewo.hpp
 *
 *  Created on: 10 mar 2018
 *      Author: Mariusz
 */

#ifndef DRZEWO_HPP_
#define DRZEWO_HPP_

#define ODLEGLOSC 10
#define DRZEWO_PUSTE 1

#include <iostream>
using namespace std;

struct wezel {  // Struktura do tworzenia nowego elementu - wezla
	wezel *up;
	wezel *right;
	wezel *left;

	int wspolczynnik_rownowagi;
	int dane;
};

class AVL_TREE {

	wezel *korzen;

public:

	AVL_TREE();  						// Konstruktor
	void dodaj_element(int wartosc); 	// dodawanie nowego wêz³a
	void wyswietl_drzewo();
	void usun_element(int wartosc);
	int ilosc_wezlow(); 				// Funkcja zwracaj¹ca ilosc elementow naszego drzewa
	int wysokosc_drzewa(); 				// Funkcja zwracanie wysokosci drzew
	wezel *zwroc_korzen() { 			// funkcja zwraca wskaznik na korzen drzewa
		return korzen;
	};

private:								// Funkcje i zmienne prywatne
	int liczba_wezlow;
	int dodawanie_wezla(wezel *&_korzen, int wartosc);
	int usuwanie_wezla(wezel *&_korzen, int wartosc);
	int wyswietlanie(wezel *_korzen, int odstep);
	int wysokosc_AVL(wezel *_korzen);
	void rotacja_RR(wezel *&_korzen);
	void rotacja_LL(wezel *&_korzen);
	void rotacja_RL(wezel *&_korzen);
	void rotacja_LR(wezel *&_korzen);
	int oblicz_bf(wezel *_korzen);
	void rotacje_AVL(wezel *&_korzen, int bf_syna);

};

#endif /* DRZEWO_HPP_ */

