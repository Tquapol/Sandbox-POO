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

bool Materiau::evolveState(vector<vector<Materiau*>>* scene) {
	if (not isSolid()) {
		int sizeX = scene->size();
		int sizeY = scene->at(0).size();
		if ((x_ == sizeX - 1) || (y_ == 0) || (y_ == sizeY - 1)) {				// L'élément disparait aux bords de la scène
			Materiau::setDensity(0);
			return true;
		}
	}
	return false;
}