// Jules ROBIN

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "IHM.h"
#include "Scene.h"
#include "RectangleBrush.h"
#include "Pierre.h"
#include "Sable.h"
#include "InerSable.h"
#include "Eau.h"

using namespace std;

int main() {
	srand(time(nullptr));

	int n = 100;
	int m = 100;
	Scene scene(n, m, false);
	RectBrosse brosse(&scene);
	IHM inte(5*n, 5*m, &scene, &brosse);

	while (true) {
		scene.setMaterial(new Sable, 10, 50);
		inte.renderSFML();
	}
	return 0;
}