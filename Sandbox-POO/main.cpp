// Jules ROBIN

#include <iostream>
#include <Windows.h>
#include "Scene.h"
#include "Pierre.h"
#include "Sable.h"
#include "Eau.h"

using namespace std;

int main() {
	Scene scene(11, 11);

	for (int i = 0; i < 7; i++) {
		scene.setMaterial(new Pierre, 10, 2 + i);
	}
	for (int i = 0; i < 3; i++) {
		scene.setMaterial(new Eau, 7, 4 + i);
		scene.setMaterial(new Eau, 6, 4 + i);
	}
	for (int i = 0; i < 3; i++) {
		scene.setMaterial(new Eau, 1+i, 6);
	}
	scene.setMaterial(new Pierre, 9, 2);
	scene.setMaterial(new Pierre, 9, 8);
	scene.setMaterial(new Pierre, 8, 2);
	scene.setMaterial(new Pierre, 8, 8);

	scene.setMaterial(new Sable, 2, 5);
	scene.setMaterial(new Sable, 1, 5);
	scene.setMaterial(new Sable, 0, 5);
	scene.print();

	for (int i = 0; i < 30; i++) {
		Sleep(500);
		system("CLS");
		scene.evolve();
		scene.print();
		if (i == 10) {
			scene.removeMaterial(10, 4);
			scene.removeMaterial(10, 7);
			scene.resize(20, 11);
		}
	}

	return 0;
}