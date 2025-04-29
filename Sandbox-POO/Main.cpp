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
    Scene scene(500, 500);
    IHM inte(500, 500);
    inte.renderSFML(&scene);

	for (int i = 0; i < 30; i++) {
		scene.setMaterial(new InerSable, 29 - i, 15);
		scene.setMaterial(new InerSable, 29 - i, 14);
		scene.setMaterial(new InerSable, 29 - i, 16);
	}

	for (int i = 0; i < 40; i++) {
		if (i == 5) {
			scene.removeMaterial(29, 15);
			scene.removeMaterial(29, 14);
			scene.removeMaterial(29, 16);
		}
		system("CLS");
		scene.print();
		scene.evolve();
		Sleep(100);
	}

	return 0;