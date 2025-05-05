//Antoine DANIEL

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "Brush.h"
#include "IHM.h"

using namespace std;
using namespace sf;


IHM::IHM(unsigned int sizeX, unsigned int sizeY, Scene* scene, Brosse* brosse, bool pause) {
	sizeX_ = sizeX;
	sizeY_ = sizeY;
    scene_ = scene;
    brosse_ = brosse;
    pause_ = pause;
    window_.create(sf::VideoMode(sizeY_, sizeX_), "Sand Project");
}


void IHM::linkScene(Scene* scene) {
    scene_ = scene;
}


void IHM::linkBrosse(Brosse* brosse) {
    brosse_ = brosse;
}


void IHM::inputs(Event* event) {
    if (event->type == Event::MouseButtonPressed) {
        if (event->mouseButton.button == Mouse::Left) {
            brosse_->putMaterial(Mouse::getPosition());
            cout << "Clic-gauche " << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
        }
        if (event->mouseButton.button == Mouse::Right) {
            brosse_->errase(Mouse::getPosition());
            cout << "Clic-droit " << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
        }
    }
    if (event->type == Event::MouseWheelScrolled) {
        int newsize = brosse_->getSize() + event->mouseWheel.delta;
        if (newsize < 1) { newsize = 1; }
        else if (newsize > int(scene_->getSizeY()/2)) { newsize = int(scene_->getSizeY() / 2); }
        brosse_->setSize(newsize);
        cout << "Brosse " << brosse_->getSize();
    }
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        pause_ = not pause_;
        cout << "Pause " << pause_ << endl;
        while (Keyboard::isKeyPressed(Keyboard::Space));
    }
    if (event->type == sf::Event::Closed) {
        window_.close();
    }
}


void IHM::renderSFML() {

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window_.pollEvent(event))
    {
        inputs(&event);
    }

    if (true) {
        scene_->evolve();
        window_.clear(sf::Color::Black);
        VertexArray quad(Quads, 4);
        vector<VertexArray> screen;
        int N = 0;
        for (int x = 0; x < scene_->getSizeX(); x++) {
            for (int y = 0; y < scene_->getSizeY(); y++) {
                Materiau* M = scene_->getMaterial(x, y);
                if (M != nullptr) {
                    quad[0].color = M->getColor();
                    quad[0].position.x = 5 * M->getPixel().position.x - 2;
                    quad[0].position.y = 5 * M->getPixel().position.y - 2;
                    quad[1].color = M->getColor();
                    quad[1].position.x = 5 * M->getPixel().position.x + 2;
                    quad[1].position.y = 5 * M->getPixel().position.y - 2;
                    quad[2].color = M->getColor();
                    quad[2].position.x = 5 * M->getPixel().position.x + 2;
                    quad[2].position.y = 5 * M->getPixel().position.y + 2;
                    quad[3].color = M->getColor();
                    quad[3].position.x = 5 * M->getPixel().position.x - 2;
                    quad[3].position.y = 5 * M->getPixel().position.y + 2;
                    screen.push_back(quad);
                    N++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            window_.draw(screen[i]);
        }
        window_.display();
    }
}

