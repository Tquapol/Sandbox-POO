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
	int n = 100;
	int m = 100;
	Scene scene(n, m, false);
	IHM inte(5*n, 5*m);

	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 20; j++) {
			scene.setMaterial(new Sable, 10 + i, 40 + j);
		}
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			scene.setMaterial(new Eau, 50 + i, 30 + j);
		}
	}

	while (true) {
		inte.renderSFML(&scene);
		scene.evolve();
	}
	return 0;
}