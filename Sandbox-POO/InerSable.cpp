#include <iostream>
#include <vector>
#include "InerSable.h"
#include "Scene.h"

using namespace std;

InerSable::InerSable(int x, int y, bool v, bool solid, unsigned int density)
	: Materiau::Materiau(x, y, solid, density) {
	inertie_ = v;
};


void InerSable::print() const {
	cout << "Sable ";
	Materiau::print();
}


bool InerSable::evolveState(vector<vector<Materiau*>>* scene, bool vide) {
	if (Materiau::evolveState(scene, vide)) {
		inertie_ = true;
		return true;
	}

	int x = Materiau::getX();
	int y = Materiau::getY();
	int d = Materiau::getDensity();

	if ((not vide) && (x == scene->size() - 1)) {
		inertie_ = false;
		return false;
	}

	Materiau* M_voisin = scene->at(x + 1).at(y);

	if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {		// gravité
		scene->at(x).at(y) = nullptr;
		Materiau::setX(x + 1);
		inertie_ = true;
		return true;
	}

	if (inertie_) {
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
	}
	inertie_ = false;
	return false;
}