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

<<<<<<< Updated upstream
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
=======
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window_.pollEvent(event))
    {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed)
            window_.close();
    }

    if (not pause_) {
        // clear the window with black color
        window_.clear(sf::Color::Black);
        VertexArray quad(Quads, 4);
        vector<VertexArray> screen;
        int N = 0;
        for (int x = 0; x < scene->getSizeX(); x++) {
            for (int y = 0; y < scene->getSizeY(); y++) {
                Materiau* M = scene->getMaterial(x, y);
                if (M != nullptr) {
                    quad[0].color = M->getColor();
                    quad[0].position.x = 9 * M->getPixel().position.x - 4;
                    quad[0].position.y = 9 * M->getPixel().position.y - 4;
                    quad[1].color = M->getColor();
                    quad[1].position.x = 9 * M->getPixel().position.x + 4;
                    quad[1].position.y = 9 * M->getPixel().position.y - 4;
                    quad[2].color = M->getColor();
                    quad[2].position.x = 9 * M->getPixel().position.x + 4;
                    quad[2].position.y = 9 * M->getPixel().position.y + 4;
                    quad[3].color = M->getColor();
                    quad[3].position.x = 9 * M->getPixel().position.x - 4;
                    quad[3].position.y = 9 * M->getPixel().position.y + 4;
                    screen.push_back(quad);
                    N++;
>>>>>>> Stashed changes
                }
            }
        }
        window_.draw(points);
        window_.display();
}