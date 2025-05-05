#pragma once
#include <SFML/Graphics.hpp>
#include "Brush.h"

using namespace sf;

class RectBrosse : public Brosse{

public :
	RectBrosse(Scene* scene = nullptr, unsigned int size = 1, string curentMaterial = "Sable");
	virtual void putMaterial(Vector2i position);
	virtual void errase(Vector2i position);
};