// Jules ROBIN

#include <iostream>
#include <vector>
#include "Scene.h"

Scene::Scene(unsigned int sizeX, unsigned int sizeY) {
	sizeX_ = sizeX;
	sizeY_ = sizeY;
	scene_ = {};
	for (int x = 0; x < sizeX; x++) {
		vector<Materiau*> v = {};
		for (int y = 0; y < sizeY; y++) {
			v.push_back(nullptr);
		}
		scene_.push_back(v);
	}
}


Scene::~Scene() {
	for (int x = 0; x < sizeX_; x++) {
		for (int y = 0; y < sizeY_; y++) {
			if (scene_[x][y] != nullptr) {
				delete scene_[x][y];
			}
		}
	}
}


void Scene::print() const{
	for (int x = 0; x < sizeX_; x++) {
		for (int y = 0; y < sizeY_; y++) {
			if (scene_[x][y] != nullptr) {
				cout << scene_[x][y]->getDensity();
			}
			else {
				cout << 0;
			}
			cout << char(9);
		}
		cout << endl;
	}
}


void Scene::resize(unsigned int sizeX, unsigned int sizeY) {
	if (sizeY < sizeY_) {
		for (int x = 0; x < sizeX_; x++) {
			for (int m = 0; m < sizeY_ - sizeY; m++) {
				if (scene_[x].back() != nullptr) {
					delete scene_[x][-1];
				}
				scene_[x].pop_back();
			}
		}
	}
	else if (sizeY > sizeY_) {
		for (int x = 0; x < sizeX_; x++) {
			for (int m = 0; m < sizeY - sizeY_; m++) {
				scene_[x].push_back(nullptr);
			}
		}
	}
	sizeY_ = sizeY;

	if (sizeX < sizeX_) {
		for (int n = 1; n <= sizeX_ - sizeX; n++) {
			for (int y = 0; y < sizeY_; y++) {
				if (scene_[sizeX_ - n][y] != nullptr) {
					delete scene_[sizeX_ - n][y];
				}
			}
			scene_.pop_back();
		}
	}
	else if (sizeX > sizeX_) {
		vector<Materiau*> V = {};
		for (int y = 0; y < sizeY_; y++) {
			V.push_back(nullptr);
		}
		for (int n = 0; n < sizeX - sizeX_; n++) {
			scene_.push_back(V);
		}
	}
	sizeX_ = sizeX;
}


Materiau* Scene::setMaterial(Materiau* M, unsigned int x, unsigned int y) {
	if ((x < sizeX_) && (y < sizeY_)) {
		Materiau* exM = getMaterial(x, y);
		if (exM != nullptr) {
			delete exM;
		}
		scene_[x][y] = M;
		M->setX(x);
		M->setY(y);
		return exM;
	}
	return nullptr;
}


void Scene::removeMaterial(unsigned int x, unsigned int y) {
	if ((x < sizeX_) && (y < sizeY_) && (scene_[x][y] != nullptr)) {
		Materiau* M = scene_[x][y];
		scene_[x][y] = nullptr;
		delete M;
	}
}