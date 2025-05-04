//Antoine DANIEL

#include"IHM.h"
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;


IHM::IHM(unsigned int sizeX, unsigned int sizeY) {
	sizeX_ = sizeX;
	sizeY_ = sizeY;
	window_.create(sf::VideoMode(sizeY_, sizeX_), "Sand Project");
}

void IHM::renderSFML(Scene* scene) {

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window_.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window_.close();
    }

    // clear the window with black color
    window_.clear(sf::Color::Black);
    vector<Vertex> screen;
    int N = 0;
    for (int x = 0; x < scene->getSizeX(); x++) {
        for (int y = 0; y < scene->getSizeY(); y++) {
            if (scene->getMaterial(x, y) != nullptr) {
                screen.push_back(scene->getMaterial(x,y)->getPixel());
                N++;
            }
        }
    }
    window_.draw(&screen[0], N, Points);
    window_.display();
}