// Jules ROBIN

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Pierre.h"

using namespace std;

Pierre::Pierre(int x, int y, string type, bool solid, unsigned int density, sf::Color color, bool inertie)
	: Materiau::Materiau(x, y, type, solid, density, color, inertie) {};

void Pierre::print() const{
	cout << "Pierre ";
	Materiau::print();
}