// Jules ROBIN

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "InerSable.h"
#include "Scene.h"

using namespace std;

InerSable::InerSable(int x, int y, string type, bool solid, unsigned int density, sf::Color color, bool inertie)
	: Materiau::Materiau(x, y, type, solid, density, color, inertie) {
};


void InerSable::print() const {
	cout << "Sable ";
	Materiau::print();
}


bool InerSable::evolveState(vector<vector<Materiau*>>* scene, bool vide) {
	if (Materiau::evolveState(scene, vide)) {
		Materiau::setInertie(true);
		return true;
	}

	int x = Materiau::getX();
	int y = Materiau::getY();
	int d = Materiau::getDensity();

	if ((not vide) && (x == scene->size() - 1)) {
		Materiau::setInertie(false);
		return false;
	}

	Materiau* M_voisin = scene->at(x + 1).at(y);

	if ((M_voisin == nullptr) || ((d > M_voisin->getDensity()) && (not M_voisin->isSolid()))) {		// gravité
		scene->at(x).at(y) = nullptr;
		Materiau::setX(x + 1);
		Materiau::setInertie(true);
		return true;
	}

	if (Materiau::isMoving()) {
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

		if (x > scene->size()-1) {							//Modifie l'inertie des matériaux environnants si il entre en colision avec quelque chose
			if (scene->at(x - 1).at(y) != nullptr) {
				scene->at(x - 1).at(y)->setInertie(true);
			}
		}
		if (y > 0) {
			if (scene->at(x).at(y - 1) != nullptr) {
				scene->at(x).at(y - 1)->setInertie(true);
			}
		}
		if (x < scene->at(0).size() - 1) {
			if (scene->at(x).at(y + 1) != nullptr) {
				scene->at(x).at(y + 1)->setInertie(true);
			}
		}
	}

	Materiau::setInertie(false);
	return false;
}