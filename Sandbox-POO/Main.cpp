// Jules ROBIN

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "IHM.h"
#include "Scene.h"
#include "Brush.h"
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
	Brosse brosse(&scene);
	IHM inte(9*n, 9*m, &scene, &brosse);
	ShowWindow(GetConsoleWindow(),0);
	while (inte.isOpen()) {
		inte.renderSFML();
	}
	return 0;
}