// Jules ROBIN

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Sable.h"
#include "Scene.h"

using namespace std;

Sable::Sable(int x, int y, string type, bool solid, unsigned int density, sf::Color color, bool inertie)
	: Materiau::Materiau(x, y, type, solid, density, color, inertie) {};


void Sable::print() const {
	cout << "Sable ";
	Materiau::print();
}


bool Sable::evolveState(vector<vector<Materiau*>>* scene, bool vide) {
	if (Materiau::evolveState(scene, vide)) {
		return true;
	}

	int x = Materiau::getX();
	int y = Materiau::getY();
	int d = Materiau::getDensity();

	if ((not vide) && (x == scene->size() - 1)) {
		return false;
	}

	Materiau* M_voisin = scene->at(x + 1).at(y);

	if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {		// gravit�
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
	return false;
}