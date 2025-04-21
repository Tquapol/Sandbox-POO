#pragma once
#include "Materiau.h"

class Sable : public Materiau {

public:
	Sable(int x = 0, int y = 0, bool solid = false, unsigned int density = 2);
	void print() const;
	//void evolveState();
};