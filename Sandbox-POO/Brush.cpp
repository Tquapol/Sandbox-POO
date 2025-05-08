// Jules ROBIN

#include <iostream>
#include <string>
#include "Scene.h"
#include "Brush.h"
#include "Pierre.h"
#include "Eau.h"
#include "Sable.h"
#include "InerSable.h"

using namespace std;

Brosse::Brosse(Scene* scene, int size, string curentMaterial) {
	size_ = size;
	curentMaterial_ = curentMaterial;
	scene_ = scene;
}

void Brosse::setSize(int size) {
	size_ = size;
}

void Brosse::linkScene(Scene* scene) {
	scene_ = scene;
}

void Brosse::setMaterial(string M) {
	curentMaterial_ = M;
}

void Brosse::putMaterial(Vector2i position) const {
	int x = position.x / 9;
	int y = position.y / 9;
	for (int i = -(size_ - 1) / 2; i < (size_ - 1) / 2 + 1; i++) {
		for (int j = -(size_ - 1) / 2; j < (size_ - 1) / 2 + 1; j++) {
			if ((y + i >= 0) && (y + i < scene_->getSizeX()) && (x + j >= 0) && (x + j < scene_->getSizeY())) {
				if (scene_->getMaterial(y + i, x + j) == nullptr) {
					if (curentMaterial_ == "Pierre") { scene_->setMaterial(new Pierre, y + i, x + j); }
					else if (curentMaterial_ == "Eau") { scene_->setMaterial(new Eau, y + i, x + j); }
					else if (curentMaterial_ == "Sable") { scene_->setMaterial(new Sable, y + i, x + j); }
					else { scene_->setMaterial(new InerSable, y + i, x + j); }
				}
			}
		}
	}
}


void Brosse::errase(Vector2i position) const {
	int x = position.x / 9;
	int y = position.y / 9;
	for (int i = -(size_ - 1) / 2; i < (size_ - 1) / 2 + 1; i++) {
		for (int j = -(size_ - 1) / 2; j < (size_ - 1) / 2 + 1; j++) {
			scene_->removeMaterial(y + i, x + j);
		}
	}
}