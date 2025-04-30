// Jules ROBIN

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Eau.h"

using namespace std;

Eau::Eau(int x, int y, bool solid, unsigned int density, sf::Color color)
	: Materiau::Materiau(x, y, solid, density, color) {};

void Eau::print() const {
	cout << "Eau ";
	Materiau::print();
}


bool Eau::evolveState(vector<vector<Materiau*>>* scene, bool vide) {
	if (Materiau::evolveState(scene, vide)) {
		return true;
	}

	int x = Materiau::getX();
	int y = Materiau::getY();
	int d = Materiau::getDensity();

	if ((not vide) && (x == scene->size() - 1)) {
		int n = rand() % 2;
		for (int i = 0; i < 2; i++) {														// écoulement
			Materiau* M_voisin = scene->at(x).at(y + 1 - 2 * n);
			if (M_voisin == nullptr) {														// les éléments ne changent pas de position horizontalement malgré les différences de densité
				scene->at(x).at(y) = nullptr;
				Materiau::setY(y + 1 - 2 * n);
				return true;
			}
			n = 1 - n;
		}
		return false;
	}

	Materiau* M_voisin = scene->at(x + 1).at(y);

	if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {		// gravité
		scene->at(x).at(y) = nullptr;
		Materiau::setX(x + 1);
		return true;
	}

	int n = rand() % 2;		// 0 ou 1
	for (int i = 0; i < 2; i++) {														// glissement
		M_voisin = scene->at(x + 1).at(y + 1 - 2 * n);
		if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {
			scene->at(x).at(y) = nullptr;
			Materiau::setX(x + 1);
			Materiau::setY(y + 1 - 2 * n);
			return true;
		}
		n = 1 - n;		// 0 si n = 1 / 1 si n = 0
	}

	n = rand() % 2;
	for (int i = 0; i < 2; i++) {														// écoulement
		M_voisin = scene->at(x).at(y + 1 - 2 * n);
		if (M_voisin == nullptr) {														// les éléments ne changent pas de position horizontalement malgré les différences de densité
			scene->at(x).at(y) = nullptr;
			Materiau::setY(y + 1 - 2 * n);
			return true;
		}
		n = 1 - n;
	}
	return false;
}