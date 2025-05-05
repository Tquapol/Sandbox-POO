#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "RectangleBrush.h"
#include "Brush.h"
#include "Materiau.h"
#include "Sable.h"
#include "Eau.h"
#include "Pierre.h"
#include "InerSable.h"

using namespace std;
using namespace sf;

RectBrosse::RectBrosse(Scene* scene, unsigned int size, string curentMaterial)
	: Brosse::Brosse(size, curentMaterial, scene){}


void RectBrosse::putMaterial(Vector2i position) {

}


void RectBrosse::errase(Vector2i position) {

}