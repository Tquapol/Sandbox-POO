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
    mouseLeft_ = false;
    mouseRight_ = false;
    window_.setFramerateLimit(60);              //limite des FPS
    window_.setVerticalSyncEnabled(true);       //synchronisation verticale
}

void IHM::setSize(unsigned int x, unsigned int y) {
    sizeX_ = x;
    sizeY_ = y;
}

void IHM::leftClic() {
    mouseLeft_ = true;
}

void IHM::rightClic() {
    mouseRight_ = true;
}

void IHM::releaseClic() {
    mouseLeft_ = false;
    mouseRight_ = false;
}


void IHM::linkScene(Scene* scene) {
    scene_ = scene;
}


void IHM::linkBrosse(Brosse* brosse) {
    brosse_ = brosse;
}


void IHM::inputs(Event* event) {                        //La fonction input prend en comte clavier et sourie
    if (event->type == Event::MouseButtonPressed) {
        if (event->mouseButton.button == Mouse::Left) {
            leftClic();
        }
        if (event->mouseButton.button == Mouse::Right) {
            rightClic();
        }
    }
    if (event->type == Event::MouseButtonReleased) {
        releaseClic();
    }

    if (event->type == Event::MouseWheelScrolled) {             //Augmente ou diminue la taille de la brosse selon le scroll de la molette
        int newsize = brosse_->getSize();
        if (event->mouseWheelScroll.delta > 0) { newsize = newsize + 2; }
        if (event->mouseWheelScroll.delta < 0) { newsize = newsize - 2; }
        if (newsize < 1) { newsize = 1; }
        else if (newsize > int(scene_->getSizeY()/2)) { newsize = int(scene_->getSizeY() / 2); }
        brosse_->setSize(newsize);
    }

    if (event->type == Event::KeyPressed) {
        if(event->key.scancode == Keyboard::Scancode::Space){
            pause_ = not pause_;
        }
        if (event->key.scancode == Keyboard::Scancode::G) {
            scene_->switchGround();
        }
        if ((event->key.shift)&&(event->key.scancode == Keyboard::Scancode::X)) {
            scene_->errase();
        }
        if (event->key.scancode == Keyboard::Scancode::Num1) {
            brosse_->setMaterial("Pierre");
        }
        if (event->key.scancode == Keyboard::Scancode::Num2) {
            brosse_->setMaterial("Eau");
        }
        if (event->key.scancode == Keyboard::Scancode::Num3) {
            brosse_->setMaterial("Sable");
        }
        if (event->key.scancode == Keyboard::Scancode::Num4) {
            brosse_->setMaterial("InerSable");
        }
        if ((event->key.alt) && (event->key.scancode == Keyboard::Scancode::F4)) {
            window_.close();
        }
    }

    /*
    if (event->type == Event::Resized) {
        scene_->resize(event->size.height / 9, event->size.width / 9);
        setSize(event->size.width, event->size.height);
        window_.setSize(Vector2u(event->size.width, event->size.height));
    }
    */

    if (event->type == sf::Event::Closed) {
        window_.close();
    }
}


void IHM::hud() {
    Font font;
    int fontSize = 20;
    if (font.loadFromFile("arial.ttf")) {
        Text input1("1 : Pierre", font, fontSize);
        Text input2("2 : Eau", font, fontSize);
        Text input3("3 : Sable", font, fontSize);
        Text input4("4 : Inersable", font, fontSize);
        Text inputG("G : Sol", font, fontSize);
        Text inputX("Shift-X : Effacer", font, fontSize);
        Text inputSp("Space : Pause", font, fontSize);
        Text inputLC("Left-Clic : Dessiner", font, fontSize);
        Text inputRC("Right-Clic : Gommer", font, fontSize);
        Text inputMol("Wheel UP/DOWN : Taille de la brosse", font, fontSize);

        Text ON("ON", font, fontSize);
        Text OFF("OFF", font, fontSize);
        ON.setFillColor(Color::Green);
        OFF.setFillColor(Color::Red);

        input1.setPosition(Vector2f(5, 10));
        input2.setPosition(Vector2f(5, 10 + fontSize + 5));
        input3.setPosition(Vector2f(5, 10 + 2 * (fontSize + 5)));
        input4.setPosition(Vector2f(5, 10 + 3 * (fontSize + 5)));

        inputSp.setPosition(Vector2f(25 + 7 * fontSize, 10));
        inputG.setPosition(Vector2f(25 + 7 * fontSize, 10 + fontSize + 5));
        inputX.setPosition(Vector2f(25 + 7 * fontSize, 10 + 2 * (fontSize + 5)));

        inputLC.setPosition(Vector2f(15 + 20 * fontSize, 10));
        inputRC.setPosition(Vector2f(15 + 20 * fontSize, 10 + fontSize + 5));
        inputMol.setPosition(Vector2f(15 + 20 * fontSize, 10 + 2 * (fontSize + 5)));

        window_.draw(input1);
        window_.draw(input2);
        window_.draw(input3);
        window_.draw(input4);
        window_.draw(inputSp);
        window_.draw(inputG);
        window_.draw(inputX);
        window_.draw(inputLC);
        window_.draw(inputRC);
        window_.draw(inputMol);

        if (pause_) {
            ON.setPosition(Vector2f(25 + 15 * fontSize, 10));
            window_.draw(ON);
        }
        else {
            OFF.setPosition(Vector2f(25 + 15 * fontSize, 10));
            window_.draw(OFF);
        }
        if (scene_->isGroundOn()) {
            ON.setPosition(Vector2f(25 + 15 * fontSize, 10 + fontSize + 5));
            window_.draw(ON);
        }
        else {
            OFF.setPosition(Vector2f(25 + 15 * fontSize, 10 + fontSize + 5));
            window_.draw(OFF);
        }
    }
}


void IHM::renderSFML() {

    sf::Event event;                    
    while (window_.pollEvent(event))        // 1.Traite si il y a un input
    {
        inputs(&event);
    }

    if (mouseLeft_) {                                           // 2.Ajoute ou retire un materiau tant que la sourie est enfoncée
        brosse_->putMaterial(Mouse::getPosition(window_));
    }
    else if (mouseRight_) {
        brosse_->errase(Mouse::getPosition(window_));
    }

    if (not pause_) {           // Fait evoluer la scene si le jeu n'est pas en pause
        scene_->evolve();
    }

    window_.clear(sf::Color::Black);        // Met a jour l'affichage
    VertexArray quad(Quads, 4);
    vector<VertexArray> screen;
    int N = 0;
    for (int x = 0; x < scene_->getSizeX(); x++) {
        for (int y = 0; y < scene_->getSizeY(); y++) {
            Materiau* M = scene_->getMaterial(x, y);
            if (M != nullptr) {
                quad[0].color = M->getColor();
                quad[0].position.x = 9 * M->getPixel().position.x;
                quad[0].position.y = 9 * M->getPixel().position.y;
                quad[1].color = M->getColor();
                quad[1].position.x = 9 * M->getPixel().position.x + 8;
                quad[1].position.y = 9 * M->getPixel().position.y;
                quad[2].color = M->getColor();
                quad[2].position.x = 9 * M->getPixel().position.x + 8;
                quad[2].position.y = 9 * M->getPixel().position.y + 8;
                quad[3].color = M->getColor();
                quad[3].position.x = 9 * M->getPixel().position.x;
                quad[3].position.y = 9 * M->getPixel().position.y + 8;
                screen.push_back(quad);
                N++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        window_.draw(screen[i]);
    }
    sf::RectangleShape rectangle = brosse_->showBrush(Mouse::getPosition(window_));
    window_.draw(rectangle);
    hud();
    window_.display();
}
