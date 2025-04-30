// Jules ROBIN

#pragma once
#include <SFML/Graphics.hpp>
#include "Materiau.h"

class Pierre : public Materiau{

public :
	Pierre(int x = 0, int y = 0, bool solid = true, unsigned int density = 3, sf::Color color = sf::Color::White);
	void print() const;
};