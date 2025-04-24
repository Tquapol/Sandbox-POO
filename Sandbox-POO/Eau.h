// Jules ROBIN

#pragma once
#include <vector>
#include "Materiau.h"

using namespace std;

class Eau : public Materiau {

public:
	Eau(int x = 0, int y = 0, bool solid = false, unsigned int density = 1);
	void print() const;
	bool evolveState(vector<vector<Materiau*>> scene);
};