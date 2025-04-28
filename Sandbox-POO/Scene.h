// Jules ROBIN

#pragma once
#include <vector>
#include "Materiau.h"

using namespace std;

class Scene {
	unsigned int sizeX_;
	unsigned int sizeY_;
	vector<vector<Materiau*>> scene_;
public :
	Scene(unsigned int sizeX = 500, unsigned int sizeY = 500);
	~Scene();
	unsigned int getSizeX() const { return sizeX_; }
	unsigned int getSizeY() const { return sizeY_; }
	void resize(unsigned int sizeX, unsigned int sizeY);
	Materiau* getMaterial(unsigned int x, unsigned int y) const { return scene_[x][y]; }
	Materiau* setMaterial(Materiau* M, unsigned int x, unsigned int y);
	void removeMaterial(unsigned int x, unsigned int y);
	void print() const;
	void evolve();
};