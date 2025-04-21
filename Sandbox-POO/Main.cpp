// Jules ROBIN

#include <iostream>
#include "Materiau.h"

using namespace std;

int main() {
	Materiau m1;
	Materiau m2(10, 20, true, 3);
	m1.print();
	m2.print();

	cout << m2.getX() << endl;
	cout << m2.getY() << endl;
	cout << m2.isSolid() << endl;
	cout << m2.getDensity() << endl;
	return 0;
}