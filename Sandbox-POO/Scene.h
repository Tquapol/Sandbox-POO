// Jules ROBIN

#pragma once
#include <vector>
#include "Materiau.h"

using namespace std;

class Scene {
	unsigned int sizeX_;
	unsigned int sizeY_;
	bool vide_;
	vector<vector<Materiau*>> scene_;
public :
	Scene(unsigned int sizeX = 500, unsigned int sizeY = 500, bool vide = true);
	~Scene();
	unsigned int getSizeX() const { return sizeX_; }
	unsigned int getSizeY() const { return sizeY_; }
	void resize(unsigned int sizeX, unsigned int sizeY);
	void switchGround();
	void errase();
	Materiau* getMaterial(unsigned int x, unsigned int y) const { return scene_[x][y]; }
	Materiau* setMaterial(Materiau* M, unsigned int x, unsigned int y);
	bool isGroundOn() const { return not vide_; };
	void removeMaterial(unsigned int x, unsigned int y);
	void print() const;
	void evolve();
};