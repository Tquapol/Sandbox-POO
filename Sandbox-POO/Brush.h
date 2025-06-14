// Jules ROBIN

#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Scene;

class Brosse {
	int size_;
	string curentMaterial_;

	Scene* scene_;
public :
	Brosse(Scene* scene = nullptr, int size = 3, string curentMaterial = "InerSable");
	void linkScene(Scene* scene);
	int getSize() const { return size_; }
	void setSize(int size);
	void setMaterial(string M);
	void putMaterial(Vector2i position) const;
	void errase(Vector2i position) const;
	RectangleShape showBrush(Vector2i position);
};