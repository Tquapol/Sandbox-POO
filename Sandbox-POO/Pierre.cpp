// Jules ROBIN

#include <iostream>
#include "Pierre.h"

using namespace std;

Pierre::Pierre(int x, int y, bool solid, unsigned int density, sf::Color color)
	: Materiau::Materiau(x, y, solid, density, color) {};

void Pierre::print() const{
	cout << "Pierre ";
	Materiau::print();
}