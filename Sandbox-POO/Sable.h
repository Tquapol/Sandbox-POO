// Jules ROBIN

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Materiau.h"

using namespace std;

class Sable : public Materiau {
public:
	Sable(int x = 0, int y = 0, bool solid = false, unsigned int density = 2, sf::Color color = sf::Color::Yellow);
	void print() const;
	bool evolveState(vector<vector<Materiau*>>* scene, bool vide);
};