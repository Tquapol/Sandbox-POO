// Jules ROBIN

#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Materiau.h"

using namespace std;

class InerSable : public Materiau {

public:
	InerSable(int x = 0, int y = 0, string type = "InerSable", bool solid = false, unsigned int density = 2, sf::Color color = sf::Color(224,205,169,255), bool inertie = false);
	void print() const;
	bool evolveState(vector<vector<Materiau*>>* scene, bool vide);
};