// Jules ROBIN

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <string>
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
	ShowWindow(GetConsoleWindow(), 1);		//ferme la console
	system("CLS");		//Recupere les dimentions de la scene
	string str_n;
	string str_m;
	cout << "Longueur de la grille : ";
	getline(cin, str_m);
	cout << "Hauteur de la grille : ";
	getline(cin, str_n);
	int n = stoi(str_n);
	int m = stoi(str_m);

	Scene scene(n, m, false);		//initialise la scene, la brosse et la fenetre
	Brosse brosse(&scene);
	IHM inte(9*n, 9*m, &scene, &brosse);

	ShowWindow(GetConsoleWindow(),0);		//ferme la console

	while (inte.isOpen()) {		//boucle le programme pour rafraichir la fenetre
		inte.renderSFML();
	}
	return 0;
}