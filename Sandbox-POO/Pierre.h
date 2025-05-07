// Jules ROBIN

#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Materiau.h"

class Pierre : public Materiau{

public :
	Pierre(int x = 0, int y = 0, string type = "Pierre", bool solid = true, unsigned int density = 3, sf::Color color = sf::Color(132,138,134,255), bool inertie = false);
	void print() const;
};