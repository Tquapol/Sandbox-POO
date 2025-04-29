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
    while (window_.isOpen())
    {
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
        for (int x = 1; x < sizeX_; x++) {
            for (int y = 1; y < sizeY_; y++) {
                sf::VertexArray point(sf::Points,1);
                point[0].position = sf::Vector2f(float(y), float(x));
                if (scene->getMaterial(x, y) == nullptr) {
                    point[0].color = sf::Color::Transparent;
                }
                else {
                    point[0].color = scene->getMaterial(x, y)->getColor();
                }
                window_.draw(point);
            }
        }
        
        window_.display();
    }
	
}