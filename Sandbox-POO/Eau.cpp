#include <iostream>
#include "Eau.h"

using namespace std;

Eau::Eau(int x, int y, bool solid, unsigned int density)
	: Materiau::Materiau(x, y, solid, density) {};

void Eau::print() const {
	cout << "Eau ";
	Materiau::print();
}