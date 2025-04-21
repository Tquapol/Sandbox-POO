#pragma once
#include "Materiau.h"

class Eau : public Materiau {

public:
	Eau(int x = 0, int y = 0, bool solid = false, unsigned int density = 1);
	void print() const;
	//void evolveState();
};