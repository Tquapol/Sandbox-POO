// Jules ROBIN

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Materiau.h"

using namespace std;

Materiau::Materiau(int x, int y, string type, bool solid, unsigned int density, sf::Color color, bool moved, bool inertie) {
	pixel_.position.x = x;
	pixel_.position.y = y;
	solid_ = solid;
	density_ = density;
	pixel_.color = color;
	moved_ = moved;
	type_ = type;
	inertie_ = inertie;
}

void Materiau::setX(int x) {		//Les coordonnées x et y sont inversées entre la scène et la fenêtre
	pixel_.position.y = x;
}

void Materiau::setY(int y) {
	pixel_.position.x = y;
}

void Materiau::setDensity(unsigned int d) {
	density_ = d;
}

void Materiau::setMovedAt(bool m) {
	moved_ = m;
}

void Materiau::setInertie(bool v) {
	inertie_ = v;
}

void Materiau::print() const {
	cout << "(Position :(" << getX() << "," << getY() << "), ";
	cout << "Solide :" << solid_ << ", ";
	cout << "Densite :" << density_ << ")" << endl;
}

bool Materiau::evolveState(vector<vector<Materiau*>>* scene, bool vide) {
	if (not isSolid()) {
		int sizeX = scene->size();
		int sizeY = scene->at(0).size();
		int n = rand() % 2;
		if (vide) {
			if (getX() == sizeX - 1) {
				Materiau::setDensity(0);
				return true;
			}
			if (((getY() == 0) || (getY() == sizeY - 1)) && (scene->at(getX() + 1).at(getY()) != nullptr)) {
				if ((getY() + 1 - 2 * n > sizeY - 1) || (getY() + 1 - 2 * n < 0)) {
					Materiau::setDensity(0);
				}
				else {
					pixel_.position.x = getY() + 1 - 2 * n;
				}
				return true;
			}
		}
		else {
			if (getX() == sizeX - 1) {
				if ((getY() == 0) || (getY() == sizeY - 1)) {
					Materiau::setDensity(0);
					return true;
				}
			}
			else {
				if (((getY() == 0) || (getY() == sizeY - 1)) && (scene->at(getX() + 1).at(getY()) != nullptr)) {
						Materiau::setDensity(0);
					return true;
				}
			}
		}
	}
	return false;
}