#include <iostream>
#include "Sable.h"

using namespace std;

Sable::Sable(int x, int y, bool solid, unsigned int density)
	: Materiau::Materiau(x, y, solid, density) {};

void Sable::print() const {
	cout << "Sable ";
	Materiau::print();
}