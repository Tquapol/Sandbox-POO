//Antoine DANIEL

#include"IHM.h"
#include<SFML/Graphics.hpp>

using namespace std;


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
    sf::VertexArray point(sf::Points, 1);
    for (int x = 0; x < scene->getSizeX(); x++) {
        for (int y = 0; y < scene->getSizeY(); y++) {
            for (int n = -2; n < 3; n++) {
                for (int m = -2; m < 3; m++) {
                    if (scene->getMaterial(x, y) != nullptr) {
                        point[0].position = sf::Vector2f(float(2 + 5 * y + n), float(2 + 5 * x + m));
                        point[0].color = scene->getMaterial(x, y)->getColor();
                        window_.draw(point);
                    }
                }
            }
        }
    }
    window_.display();
}