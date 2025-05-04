// Jules ROBIN

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Materiau {
	Vertex pixel_;
	bool solid_;
	unsigned int density_;
	//*
	// La densité définit si le matériau va couler ou floter.
	// A densités égale les matériaux se superposent.
	// A densités différentes c'est le matériau le plus lourd qui coule (si liquide).
	// Les solides auront une densité "infinie".
	//*
	bool moved_;		// définit si un matériau a évolué ou pas
public:
	Materiau(int x = 0, int y = 0, bool solid = false, unsigned int density = 0, Color color = Color::Transparent, bool moved = false);
	int getX() const { return pixel_.position.y; }
	int getY() const { return pixel_.position.x; }
	Vertex getPixel() { return pixel_; }
	unsigned int getDensity() const { return density_; }
	bool hasMoved() const { return moved_; }
	bool isSolid() const { return solid_; }
	void setX(int x);
	void setY(int y);
	void setMovedAt(bool m);
	void setDensity(unsigned int d);
	virtual void print() const;
	sf::Color getColor() const { return pixel_.color; }
	virtual bool evolveState(vector<vector<Materiau*>>* scene, bool vide);
};