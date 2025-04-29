//Antoine DANIEL

#include"IHM.h"
#include<SFML/Graphics.hpp>

using namespace std;


IHM::IHM(unsigned int sizeX, unsigned int sizeY) {
	sizeX_ = sizeX;
	sizeY_ = sizeY;
	window_.create(sf::VideoMode(sizeY_, sizeX_), "Sand Project");
    window_.setFramerateLimit(60);
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

        sf::VertexArray points(sf::Points);
        for (int x = 1; x < sizeX_; x++) {
            for (int y = 1; y < sizeY_; y++) {
                sf::Vertex point;
                if (scene->getMaterial(x, y) != nullptr) {
                    point.position = sf::Vector2f(float(y), float(x));
                    point.color = scene->getMaterial(x, y)->getColor();
                    points.append(point);
                }
            }
        }
        window_.draw(points);
        window_.display();
}