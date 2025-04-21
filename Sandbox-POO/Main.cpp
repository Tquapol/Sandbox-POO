// Jules ROBIN

#include <iostream>
#include "Pierre.h"
#include "Sable.h"
#include "Eau.h"

using namespace std;

int main() {
	Pierre p(10, 20);
	Sable s(100, 30);
	Eau e;
	p.print();
	s.print();
	e.print();
	cout << (p.getDensity() > s.getDensity());
	return 0;
}