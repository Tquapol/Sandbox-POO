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

void Materiau::print() const {
	cout << "(Position :(" << x_ << "," << y_ << "), ";
	cout << "Solide :" << solid_ << ", ";
	cout << "Densite :" << density_ << ")" << endl;
}