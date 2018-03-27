#include "przejscia.hpp"

void pre_order(wezel *_korzen) { // Funkcja prezentuj¹ca przejscie pre-order wystarczy podac jako argument wskaznik na korzen drzewa

	if (_korzen == NULL) {	// Je¿eli element nie istnieje konczy dzia³anie funkcji
		return;
	}

	cout << _korzen->dane << "  ";

	pre_order(_korzen->left);
	pre_order(_korzen->right);
}

void in_order(wezel *_korzen) {	// Funkcja prezentuj¹ca przejscie in-order wystarczy podac jako argument wskaznik na korzen drzewa

	if (_korzen == NULL) {	// Je¿eli element nie istnieje konczy dzia³anie funkcji
		return;
	}

	in_order(_korzen->left);
	cout << _korzen->dane << "  ";
	in_order(_korzen->right);

}

void post_order(wezel *_korzen) {// Funkcja prezentuj¹ca przejscie post-order wystarczy podac jako argument wskaznik na korzen drzewa

	if (_korzen == NULL) {	 // Je¿eli element nie istnieje konczy dzia³anie funkcji
		return;
	}
	post_order(_korzen->left);
	post_order(_korzen->right);

	cout << _korzen->dane << "  ";

}
