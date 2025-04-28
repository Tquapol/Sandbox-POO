//Antoine DANIEL

#pragma once

#include<SFML/Graphics.hpp>
#include"Scene.h"

using namespace std;

class IHM {
	sf::RenderWindow window_;
	unsigned int sizeX_;
	unsigned int sizeY_;
public:
	IHM(unsigned int sizeX = 500, unsigned int sizeY = 500);
	void renderSFML(Scene* scene);
};
