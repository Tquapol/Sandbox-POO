// Jules ROBIN

#include <iostream>
#include "Materiau.h"

using namespace std;

Materiau::Materiau(int x, int y, bool solid, unsigned int density) {
	x_ = x;
	y_ = y;
	solid_ = solid;
	density_ = density;
}

void Materiau::setX(int x) {
	x_ = x;
}

void Materiau::setY(int y) {
	y_ = y;
}

void Materiau::setDensity(unsigned int d) {
	density_ = d;
}

void Materiau::setMovedAt(bool m) {
	moved_ = m;
}

void Materiau::print() const {
	cout << "(Position :(" << x_ << "," << y_ << "), ";
	cout << "Solide :" << solid_ << ", ";
	cout << "Densite :" << density_ << ")" << endl;
}

bool Materiau::evolveState(vector<vector<Materiau*>>* scene, bool vide) {
	if (not isSolid()) {
		int sizeX = scene->size();
		int sizeY = scene->at(0).size();
		int n = rand() % 2;
		if (vide) {
			if (x_ == sizeX - 1){
				Materiau::setDensity(0);
				return true;
			}
			if (((y_ == 0) || (y_ == sizeY - 1)) && (scene->at(x_ + 1).at(y_) != nullptr)) {
				if ((y_ + 1 - 2 * n > sizeY - 1)||(y_ + 1 - 2 * n < 0)) {
					Materiau::setDensity(0);
				}
				else {
					y_ = y_ + 1 - 2 * n;
				}
				return true;
			}
		}
		else {
			if (x_ == sizeX - 1) {
				if ((y_ == 0) || (y_ == sizeY - 1)) {
					Materiau::setDensity(0);
					return true;
				}
			}
			else {
				if (((y_ == 0) || (y_ == sizeY - 1)) && (scene->at(x_ + 1).at(y_) != nullptr)) {
					if ((y_ + 1 - 2 * n > sizeY - 1) || (y_ + 1 - 2 * n < 0)) {
						Materiau::setDensity(0);
					}
					else {
						y_ = y_ + 1 - 2 * n;
					}
					return true;
				}
			}
		}
	}
	return false;
}