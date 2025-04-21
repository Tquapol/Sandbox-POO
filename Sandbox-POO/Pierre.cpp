// Jules ROBIN

#include <iostream>
#include "Pierre.h"

using namespace std;

Pierre::Pierre(int x, int y, bool solid, unsigned int density)
	: Materiau::Materiau(x, y, solid, density) {};

void Pierre::print() const{
	cout << "Pierre ";
	Materiau::print();
}