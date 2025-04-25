// Jules ROBIN

#pragma once
#include <vector>
#include "Materiau.h"

using namespace std;

class Sable : public Materiau {

public:
	Sable(int x = 0, int y = 0, bool solid = false, unsigned int density = 2);
	void print() const;
	bool evolveState(vector<vector<Materiau*>>* scene);
};