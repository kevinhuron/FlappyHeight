//
// Created by Kévin HURON on 18/04/2017.
//

#ifndef GAME_SCORESCREEN_HH
#define GAME_SCORESCREEN_HH

#include <SFML/Graphics.hpp>
#include "Results.hh"

using namespace sf;

class ScoreScreen {

public:
    void Show(RenderWindow &window, int &windowWidth, int &windowHeight, Font &font, Results &results);
};


#endif //GAME_SCORESCREEN_HH
