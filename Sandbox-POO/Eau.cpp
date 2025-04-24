// Jules ROBIN

#include <iostream>
#include "Eau.h"

using namespace std;

Eau::Eau(int x, int y, bool solid, unsigned int density)
	: Materiau::Materiau(x, y, solid, density) {};

void Eau::print() const {
	cout << "Eau ";
	Materiau::print();
}


bool Eau::evolveState(vector<vector<Materiau*>> scene) {
	Materiau* M_voisin = scene[Materiau::getX() + 1][Materiau::getY()];

	if ((M_voisin == nullptr) || (Materiau::getDensity() > M_voisin->getDensity())) {		// gravit�
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

	n = rand() % 2;
	for (int i = 0; i < 2; i++) {														// �coulement
		M_voisin = scene[Materiau::getX() + 1][Materiau::getY() + 1 - 2 * n];
		if (M_voisin == nullptr) {														// les �l�ments ne changent pas de position horizontalement malgr� les diff�rences de densit�
			Materiau::setY(Materiau::getY() + 1 - 2 * n);
			return true;
		}
		n = 1 - n;
	}
	return false;
}