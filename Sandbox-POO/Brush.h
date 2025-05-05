#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Scene;

class Brosse {
	unsigned int size_;
	string curentMaterial_;

	Scene* scene_;
public :
	Brosse(unsigned int size, string curentMaterial = "Sable", Scene* scene = nullptr);
	int getSize() const { return size_; }
	void linkScene(Scene* scene);
	void setSize(unsigned int size);
	void setMaterial(string M);
	virtual void putMaterial(Vector2i position) = 0;
	virtual void errase(Vector2i position) = 0;
};