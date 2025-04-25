#include <iostream>
#include <vector>
#include "Sable.h"
#include "Scene.h"

using namespace std;

Sable::Sable(int x, int y, bool solid, unsigned int density)
	: Materiau::Materiau(x, y, solid, density) {};


void Sable::print() const {
	cout << "Sable ";
	Materiau::print();
}


bool Sable::evolveState(vector<vector<Materiau*>> scene) {
	if (Materiau::evolveState(scene)) {
		return true;
	}

	int x = Materiau::getX();
	int y = Materiau::getY();
	int d = Materiau::getDensity();

	Materiau* M_voisin = scene[x + 1][y];

	if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {		// gravité
		Materiau::setX(x + 1);
		return true;
	}

	int n = rand() % 2;		// 0 ou 1
	for (int i = 0; i < 2; i++) {														// glissement
		M_voisin = scene[x + 1][y + 1 - 2 * n];
		if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {
			Materiau::setX(x + 1);
			Materiau::setY(y + 1 - 2 * n);
			return true;
		}
		n = 1 - n;		// 0 si n = 1 / 1 si n = 0
	}
	return false;
}