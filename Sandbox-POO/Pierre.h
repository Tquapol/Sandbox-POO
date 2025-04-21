#pragma once
#include "Materiau.h"

class Pierre : public Materiau{

public :
	Pierre(int x = 0, int y = 0, bool solid = true, unsigned int density = 10000);
	void print() const;
	//void evolveState();
};