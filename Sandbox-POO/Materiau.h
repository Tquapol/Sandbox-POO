// Jules ROBIN

#pragma once

class Materiau {
	int x_;
	int y_;
	bool solid_;
	unsigned int density_;
	//*
	// La densit� d�finit si le mat�riau va couler ou floter.
	// A densit�s �gale les mat�riaux se superposent.
	// A densit�s diff�rentes c'est le mat�riau le plus lourd qui coule (si liquide).
	// Les solides auront une densit� "infinie".
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