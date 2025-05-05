//Antoine DANIEL

#pragma once

#include<SFML/Graphics.hpp>
class Scene;
class Brosse;

using namespace std;
using namespace sf;

class IHM {
	sf::RenderWindow window_;
	unsigned int sizeX_;
	unsigned int sizeY_;
	bool pause_;

	Scene* scene_;
	Brosse* brosse_;
public:
	IHM(unsigned int sizeX = 500, unsigned int sizeY = 500, Scene* scene = nullptr, Brosse* brosse = nullptr, bool pause = false);
	bool isOpen() const { return window_.isOpen(); }
	void linkScene(Scene* scene);
	void linkBrosse(Brosse* brosse);
	void inputs(Event* event);
	void renderSFML();
};
