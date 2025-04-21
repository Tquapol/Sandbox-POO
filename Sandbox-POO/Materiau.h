// Jules ROBIN

#pragma once

class Materiau {
	int x_;
	int y_;
	bool solid_;
	unsigned int density_;
	//*
	// La densité définit si le matériau va couler ou floter.
	// A densités égale les matériaux se superposent.
	// A densités différentes c'est le matériau le plus lourd qui coule (si liquide).
	// Les solides auront une densité "infinie".
	//*
public:
	Materiau(int x = 0, int y = 0, bool solid = false, unsigned int density = 0);
	int getX() const { return x_; }
	int getY() const { return y_; }
	unsigned int getDensity() const { return density_; }
	bool isSolid() const { return solid_; }
	void setX(int x);
	void setY(int y);
	virtual void print() const;
	//virtual void evolveState() = 0;
};