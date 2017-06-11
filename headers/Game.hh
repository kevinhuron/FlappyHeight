//
// Created by Kévin HURON on 10/04/2017.
//

#ifndef GAME_GAME_HH
#define GAME_GAME_HH

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "PlayerCaracter.hh"
#include "Results.hh"
#include "Star.hh"
#include "ScoreScreen.hh"
#include "OptionScreen.hh"
#include "MenuScreen.hh"
#include "Logs.hh"

using namespace std;
using namespace sf;

class Game: public Transformable {
public:
    RenderWindow window; // the render Window
    enum GameState {MENU, GAME, SCORE, OPTIONS, GAME_OVER, END}; // Game STATE
    GameState state;
    Results results; // The score
    PlayerCaracter player; // The character player
    Font font;
    Text textScore; // Text score
    Text error; // error msg when player die
    Texture background;
    Texture floor; // Bottom Floor
    Texture topWall; // Top floor
    Sprite background_sprite;
    Sprite floor_sprite;
    Sprite top_floor_sprite;
    SoundBuffer music_game_buffer;
    Sound music_game;
    bool sounds;
    int windowWidth;
    int windowHeight;

    Game();
    void runGame();
    void menu();
    void gameLoop();
    void score();
    void options();
};


#endif //GAME_GAME_HH
