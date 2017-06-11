//
// Created by Kévin HURON on 18/04/2017.
//

#ifndef GAME_MENUSCREEN_HH
#define GAME_MENUSCREEN_HH

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class MenuScreen {

public:
    int Show(RenderWindow &window, int &windowWidth, int &windowHeight, Font &font);
};


#endif //GAME_MENUSCREEN_HH
