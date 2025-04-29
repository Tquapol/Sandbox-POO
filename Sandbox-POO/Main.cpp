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
	Scene scene(30, 19, false);

	for (int i = 0; i < 30; i++) {
		scene.setMaterial(new InerSable, 29 - i, 10);
	}

	for (int i = 0; i < 40; i++) {
		if (i == 5) {
			scene.removeMaterial(29, 10);
		}
		system("CLS");
		scene.print();
		scene.evolve();
		Sleep(200);
	}

	return 0;
}