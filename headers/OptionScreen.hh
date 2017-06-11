//
// Created by Kévin HURON on 18/04/2017.
//

#ifndef GAME_OPTIONSCREEN_HH
#define GAME_OPTIONSCREEN_HH

#include <SFML/Graphics.hpp>
#include "../headers/TimeManager.hh"
#include "PlayerCaracter.hh"
#include <iostream>

using namespace sf;
using namespace std;

class OptionScreen {

public:
    bool Show(RenderWindow &window, int &windowWidth, int &windowHeight, Font &font, bool &sounds, PlayerCaracter &player);
};


#endif //GAME_OPTIONSCREEN_HH
