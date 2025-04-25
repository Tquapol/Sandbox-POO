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
		scene.setMaterial(new Pierre, 9, 2 + i);
	}
	for (int i = 0; i < 3; i++) {
		scene.setMaterial(new Eau, 7, 4 + i);
	}
	scene.setMaterial(new Pierre, 8, 2);
	scene.setMaterial(new Pierre, 8, 8);

	scene.setMaterial(new Sable, 2, 5);
	scene.setMaterial(new Sable, 1, 5);
	scene.setMaterial(new Sable, 0, 5);
	scene.print();

	for (int i = 0; i < 20; i++) {
		Sleep(1000);
		system("CLS");
		scene.evolve();
		scene.print();
	}

	return 0;
}