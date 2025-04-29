// Jules ROBIN

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "IHM.h"
#include "Scene.h"
#include "Pierre.h"
#include "Sable.h"
#include "InerSable.h"
#include "Eau.h"

using namespace std;

int main() {
	srand(time(nullptr));
	Scene scene(500, 500, false);
	IHM inte(500, 500);


	for (int i = 0; i < 30; i++) {
		scene.setMaterial(new Sable, 29 - i, 15);
		scene.setMaterial(new Sable, 29 - i, 14);
		scene.setMaterial(new Sable, 29 - i, 16);
		scene.setMaterial(new Sable, 29 - i, 13);
		scene.setMaterial(new Sable, 29 - i, 12);
		scene.setMaterial(new Sable, 29 - i, 17);
		scene.setMaterial(new Sable, 29 - i, 11);
		scene.setMaterial(new Sable, 29 - i, 18);
		scene.setMaterial(new Sable, 29 - i, 19);
	}

	while (true) {
		scene.evolve();
		inte.renderSFML(&scene);
	}

	return 0;
}