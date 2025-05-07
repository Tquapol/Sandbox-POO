// Jules ROBIN

#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Materiau.h"

using namespace std;

class Eau : public Materiau {

public:
	Eau(int x = 0, int y = 0, string type = "Eau", bool solid = false, unsigned int density = 1, sf::Color color = sf::Color(2,91,131,255), bool inertie = false);
	void print() const;
	bool evolveState(vector<vector<Materiau*>>* scene, bool vide);
};