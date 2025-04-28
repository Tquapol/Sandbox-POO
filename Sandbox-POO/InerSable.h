// Jules ROBIN

#pragma once
#include <vector>
#include "Materiau.h"

using namespace std;

class InerSable : public Materiau {
	bool inertie_;
public:
	InerSable(int x = 0, int y = 0, bool v = false, bool solid = false, unsigned int density = 2);
	bool isMoving() const { return inertie_; }
	void setMovement(bool v);
	void print() const;
	bool evolveState(vector<vector<Materiau*>>* scene, bool vide);

};