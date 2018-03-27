/*
 * drzewo.cpp
 *
 *  Created on: 10 mar 2018
 *      Author: Mariusz
 */

#include "drzewo.hpp"

AVL_TREE::AVL_TREE() {					// Konstuktor - nadaje wartosci pocz¹tkowe
	korzen = NULL;
	liczba_wezlow = 0;

}

int AVL_TREE::ilosc_wezlow() {			// Funkcja zwracajaca informacje i ilosci wezlow uzywanych w programie

	return liczba_wezlow;

}


void AVL_TREE::dodaj_element(int wartosc) { // funkcja  do wywo³ywania funkcji dodajacej nowy element do drzewa

	dodawanie_wezla(korzen, wartosc); 		// Stosowanie tego typu funkcji jest konieczne aby uzywac rekurencji

}

int AVL_TREE::dodawanie_wezla(wezel *&_korzen, int wartosc) { // rekurencyja funkcja dodajaca nowy element

	int bf_syna = 0;					  // Zmienna przechowuj¹ca informacje o wspolczynniku rownowagi syna-
										  // -Funkcja gdy konczy swoje dzialanie zwraca  wspolczynnik rownowagi
										  // dzieki czemu napotykajac bf = -2 lub = 2 od razu wiemy jakiego rodzaju rotacje zastosowac
	if (_korzen == NULL) {			  // Jezeli korzen drzewa nie wskazuje na zaden element to tworzymy nowy wezel

		_korzen = new wezel;
		_korzen->up = _korzen;
		_korzen->left = NULL;
		_korzen->right = NULL;
		_korzen->dane = wartosc;
		_korzen->wspolczynnik_rownowagi = 0;	 // Zerowanie wspolczynnika rownowagi
		liczba_wezlow++;
		cout << "Dodano nowy wezel" << endl;	 // Komunikat

		return 0;

	} else if (wartosc > _korzen->dane) {		// Wprowadzone dane sa wiêksze? - idziemy do prawego syna

		bf_syna = dodawanie_wezla(_korzen->right, wartosc);
	} else if (wartosc <= _korzen->dane) {		// Wprowadzone dane s¹ mniejsze? - idziemy do lewego syna

		bf_syna = dodawanie_wezla(_korzen->left, wartosc);
	}
	_korzen->wspolczynnik_rownowagi = oblicz_bf(_korzen);

	if (_korzen->wspolczynnik_rownowagi < -1 || _korzen->wspolczynnik_rownowagi > 1) {  // Sprawdzamy czy po dodania nowego wezla nie trzeba dokonac roacji drzewa
		rotacje_AVL(_korzen, bf_syna);
		_korzen->wspolczynnik_rownowagi = oblicz_bf(_korzen);							// Obliczanie nowego wspolczynnika rownowagi  po rotacji
	}

	return _korzen->wspolczynnik_rownowagi;
}

void AVL_TREE::usun_element(int wartosc) { // funkcja  do wywo³ywania funkcji usuwajacej element z drzewa

	usuwanie_wezla(korzen, wartosc);

}

void AVL_TREE::usuwanie_wezla(wezel *&_korzen, int wartosc) {	// Rekurencyjna funkcja, usuwajaca element

	wezel *pomocnicza, *pom;		// zmienne pomocnicze wykorzystywane przy usuwaniu elementow
	int liczba;


	if (_korzen == NULL) {       // je¿eli drzewo jest puste zakoncz dzialanie

		return ;

	}

	if (wartosc < _korzen->dane)   // wprowadzone dane sa mniejsze ida na lewo
			{
		usuwanie_wezla(_korzen->left, wartosc);
	}


	else if (wartosc > _korzen->dane) // wprowadzone dane s¹ wieksze ida na prawo
			{
		usuwanie_wezla(_korzen->right, wartosc);
	}


	else {                        								   // w przeciwnym razie musz¹ byc rowne
		if ((_korzen->left == NULL) && (_korzen->right == NULL)) { // jezeli usuwany wezel nie ma synow
			delete (_korzen);
			_korzen = NULL;
			liczba_wezlow--;
			cout <<"Wezel zostal usuniety" << endl;
			return ;

		}

		else if (_korzen->left == NULL) { // jezeli usuwany wezel ma tylko prawego syna

			pomocnicza = _korzen->right;
			delete(_korzen);
			_korzen = pomocnicza;
			liczba_wezlow--;
			cout <<"Wezel zostal usuniety" << endl;
		} else if (_korzen->right == NULL) { // jezelu usuwany korzen ma tylko lewego syna

			pomocnicza = _korzen->left;
			delete(_korzen);
			_korzen = pomocnicza;
			liczba_wezlow--;
			cout <<"Wezel zostal usuniety" << endl;

		} else {						// jerzeli usuwany wezel ma obu synow

			pom = _korzen->left;		// wskazuje na lewego syna korzenia

			while (pom->right != NULL) {// Szukamy odpowiedniej danej, ktora bd mogli wstawic w miejsce usuwanego elementu
				pom = pom->right;
			}
			liczba = pom->dane;
			usuwanie_wezla(_korzen->left, liczba);
			_korzen->dane = liczba;

		}

	}

	_korzen->wspolczynnik_rownowagi = oblicz_bf(_korzen);								// Obliczamy wspolczynnik rownowagi
	if (_korzen->wspolczynnik_rownowagi < -1|| _korzen->wspolczynnik_rownowagi > 1) {   // Jezeli trzeba wykonujemy rotacje
		if(_korzen->wspolczynnik_rownowagi == 2){										// W zaleznosci od wartosci bf szukamy
			rotacje_AVL(_korzen, oblicz_bf(_korzen->left));								// odpowiedniej rotacji ktora musimy wykonac
		}

		else if(_korzen->wspolczynnik_rownowagi == -2){
			rotacje_AVL(_korzen, oblicz_bf(_korzen->right));
		}

		_korzen->wspolczynnik_rownowagi = oblicz_bf(_korzen);		// Oliczamy bf po rotacji
	}


}

void AVL_TREE::wyswietl_drzewo() {

	wyswietlanie(korzen, ODLEGLOSC);
}

void AVL_TREE::wyswietlanie(wezel *_korzen, int odstep) {	// Funkcja sluzaca do wyswietlania drzewa w celu sprawdzenia poprawnosci

	if (_korzen == NULL)
		return;
	odstep += ODLEGLOSC;

	wyswietlanie(_korzen->right, odstep);

	cout << endl;

	for (int i = ODLEGLOSC; i < odstep; i++)
		cout << " ";
	cout << _korzen->dane <<  endl;

	wyswietlanie(_korzen->left, odstep);
}

int AVL_TREE::wysokosc_drzewa() {

	return wysokosc_AVL(korzen);
}
int AVL_TREE::wysokosc_AVL(wezel *_korzen) {	// Funkca rekurencyjna sprawdzajaca wysokosc drzewa

	if (_korzen == NULL)
		return 0;
	else {

		int lhight = wysokosc_AVL(_korzen->left);
		int rhight = wysokosc_AVL(_korzen->right);


		if (lhight > rhight)
			return (lhight + 1);
		else
			return (rhight + 1);
	}
}

int AVL_TREE::oblicz_bf(wezel *_korzen) {	// Obliczanie wspolczynnika bd dla funkcji
	return wysokosc_AVL(_korzen->left) - wysokosc_AVL(_korzen->right);
}

void AVL_TREE::rotacja_RR(wezel *&_korzen) { // ROTACJE WEZLA RR

	wezel *pomocnicza;						// zmienna pomcnicza do wykoania rotacji
	pomocnicza = _korzen;
	_korzen = _korzen->right;
	pomocnicza->right = _korzen->left;
	_korzen->left = pomocnicza;
	pomocnicza->wspolczynnik_rownowagi = oblicz_bf(pomocnicza);
}
void AVL_TREE::rotacja_LL(wezel *&_korzen) {// ROTACJE WEZLA LL

	wezel *pomocnicza;						// zmienna pomcnicza do wykoania rotacji
	pomocnicza = _korzen;
	_korzen = _korzen->left;
	pomocnicza->left = _korzen->right;
	_korzen->right = pomocnicza;
	pomocnicza->wspolczynnik_rownowagi = oblicz_bf(pomocnicza);

}
void AVL_TREE::rotacja_RL(wezel *&_korzen) {// ROTACJE WEZLA RL

	wezel *pomocnicza, *help;			    // zmienne pomcnicza do wykoania rotacji

	pomocnicza = _korzen;
	_korzen = _korzen->right;
	help = _korzen;
	_korzen = _korzen->left;

	help->left = _korzen->right;
	_korzen->right = help;
	pomocnicza->right = _korzen->left;
	_korzen->left = pomocnicza;
	pomocnicza->wspolczynnik_rownowagi = oblicz_bf(pomocnicza);
	help->wspolczynnik_rownowagi = oblicz_bf(help);

}
void AVL_TREE::rotacja_LR(wezel *&_korzen) { // ROTACJE WEZLA LR

	wezel *pomocnicza, *help;				 // zmienne pomcnicza do wykoania rotacji

	pomocnicza = _korzen;
	_korzen = _korzen->left;
	help = _korzen;
	_korzen = _korzen->right;

	help->right = _korzen->left;
	_korzen->left = help;
	pomocnicza->left = _korzen->right;
	_korzen->right = pomocnicza;
	pomocnicza->wspolczynnik_rownowagi = oblicz_bf(pomocnicza);
	help->wspolczynnik_rownowagi = oblicz_bf(help);

}

void AVL_TREE::rotacje_AVL(wezel *&_korzen, int bf_syna) { // Funkcja wywolujaca odpowiedna rotacje na podstawie informacji wspolczynnika rownowagi
														   // korzenia oraz wspolczynnka jego syna

	if (_korzen->wspolczynnik_rownowagi == 2) {
		if (bf_syna == 1 || bf_syna == 0) {				   // Jezeli bf syna = 1 lub 0
			rotacja_LL(_korzen);
		} else if (bf_syna == -1) {
			rotacja_LR(_korzen);
		}
	} else if (_korzen->wspolczynnik_rownowagi == -2) {
		if (bf_syna == -1 || bf_syna == 0) {
			rotacja_RR(_korzen);
		} else if (bf_syna == 1) {
			rotacja_RL(_korzen);
		}

	}

}

