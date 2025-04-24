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
	Materiau* M_voisin = scene[Materiau::getX()+1][Materiau::getY()];

	if ((M_voisin == nullptr)||(Materiau::getDensity()>M_voisin->getDensity())) {		// gravité
		Materiau::setX(Materiau::getX() + 1);
		return true;
	}

	int n = rand() % 2;		// 0 ou 1
	for (int i = 0; i < 2; i++) {														// glissement
		M_voisin = scene[Materiau::getX() + 1][Materiau::getY() + 1 - 2 * n];
		if ((M_voisin == nullptr) || (Materiau::getDensity() > M_voisin->getDensity())) {
			Materiau::setX(Materiau::getX() + 1);
			Materiau::setY(Materiau::getY() + 1 - 2 * n);
			return true;
		}
		n = 1 - n;		// 0 si n = 1 / 1 si n = 0
	}
	return false;
}