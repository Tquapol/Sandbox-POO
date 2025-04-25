// Jules ROBIN

#include <iostream>
#include <Windows.h>
#include "Scene.h"
#include "Pierre.h"
#include "Sable.h"
#include "Eau.h"

using namespace std;

int main() {
	Scene scene(9, 9);

	for (int i = 0; i < 3; i++) {
		scene.setMaterial(new Pierre, 7, 3+i);
	}
	scene.setMaterial(new Sable, 2, 4);
	scene.setMaterial(new Sable, 1, 4);
	scene.print();

	for (int i = 0; i < 10; i++) {
		Sleep(1000);
		system("CLS");
		scene.evolve();
		scene.print();
	}

	return 0;
}