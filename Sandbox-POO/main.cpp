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
	srand(time(nullptr));	//Randomise la seed pour ne pas avoir deux fois la meme simulation (random)
	int n = 100;
	int m = 100;
	Scene scene(n, m, false);		//initialise la scene, la brosse et la fenetre
	Brosse brosse(&scene);
	IHM inte(9*n, 9*m, &scene, &brosse);

	ShowWindow(GetConsoleWindow(),0);		//ferme la console

	while (inte.isOpen()) {		//boucle le programme pour rafraichir la fenetre
		inte.renderSFML();
	}
	return 0;
}