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
	RectBrosse brosse;
	Scene scene(n, m, false);
	IHM inte(5*n, 5*m, &scene, &brosse);

	while (inte.isOpen()) {
		inte.inputs();
		inte.renderSFML(&scene);
	}
	return 0;
}