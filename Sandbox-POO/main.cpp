// Jules ROBIN

#include <iostream>
#include "Scène.h"
#include "Pierre.h"
#include "Sable.h"
#include "Eau.h"

using namespace std;

int main() {
	Scene scene;
	scene.print();
	cout << endl;

	scene.setMaterial(new Pierre, 2, 2);
	scene.setMaterial(new Sable, 1, 2);
	scene.setMaterial(new Eau, 0, 2);
	scene.print();
	cout << endl;

	scene.removeMaterial(2, 2);
	scene.print();
	cout << endl;

	scene.resize(3, 8);
	scene.print();

	return 0;
}