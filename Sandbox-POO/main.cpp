// Jules ROBIN

#include <iostream>
#include <Windows.h>
#include "Scene.h"
#include "Pierre.h"
#include "Sable.h"
#include "InerSable.h"
#include "Eau.h"

using namespace std;

int main() {
	srand(time(nullptr));
	Scene scene(15, 20, false);

	scene.setMaterial(new Pierre, 10, 3);
	scene.setMaterial(new Pierre, 10, 8);
	scene.setMaterial(new Pierre, 10, 13);
	scene.setMaterial(new Pierre, 10, 18);
	scene.setMaterial(new InerSable, 9, 3);
	scene.setMaterial(new InerSable, 6, 8);
	scene.setMaterial(new Sable, 9, 13);
	scene.setMaterial(new Sable, 6, 18);

	for (int i = 0; i < 30; i++) {
		system("CLS");
		scene.print();
		scene.evolve();
		Sleep(500);
	}

	return 0;
}