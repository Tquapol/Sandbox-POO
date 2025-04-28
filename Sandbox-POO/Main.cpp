// Jules ROBIN

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "IHM.h"
#include "Scene.h"
#include "Pierre.h"
#include "Sable.h"
#include "Eau.h"

using namespace std;


int main()
{
    Scene scene(500, 500);
    IHM inte(500, 500);
    inte.renderSFML(&scene);

    return 0;
}