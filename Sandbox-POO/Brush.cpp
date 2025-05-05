#include <iostream>
#include <string>
#include "Scene.h"
#include "Brush.h"

using namespace std;

Brosse::Brosse(unsigned int size, string curentMaterial) {
	size_ = size;
	curentMaterial_ = curentMaterial;
}

void Brosse::setSize(unsigned int size) {
	size_ = size;
}

void Brosse::linkScene(Scene* scene) {
	scene_ = scene;
}

void Brosse::setMaterial(string M) {
	curentMaterial_ = M;
}