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
	int n = 500;
	int m = 500;
	Scene scene(n, m, false);
	IHM inte(n, m);

	while (true) {
		scene.setMaterial(new InerSable, 10, 250);
		scene.evolve();
		inte.renderSFML(&scene);
	}
	return 0;
}