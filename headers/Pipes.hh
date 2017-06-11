//
// Created by Kévin HURON on 10/04/2017.
//

#ifndef GAME_PIPES_HH
#define GAME_PIPES_HH

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "Character.hh"
#include "Logs.hh"

using namespace std;
using namespace sf;
class Pipes: public Transformable, public Character {

private:
    float x = 1000; // Position
    float y_up = 150;
    float y_down = 150;
    float pipe_len = 450;
    float pipe_width = 150;
    float speed = 4.5; // speed of defilement
    int free_space = 330; // Free space between two pipes

public:
    Texture texture_down_pipe;
    Texture texture_up_pipe;
    Sprite pipe_down;
    Sprite pipe_up;

    Pipes(float xx);
    int load_file();
    void rand_pipes();
    void move_pipes();

    virtual int GetFreeSpace() const;
    void SetFreeSpace(int newFreeSpace);
    virtual double GetX() const;
    void SetX(double x);
    virtual double GetY_up() const;
    void SetY_up(double newY_up);
    virtual double GetY_down() const;
    void SetY_down(double newY_down);
    virtual double GetLength() const;
    void SetLength(double newLength);
    virtual double GetWidth() const;
    void SetWidth(double newWidth);
    virtual double GetSpeed() const;
    void SetSpeed(double newSpeed);
};


#endif //GAME_PIPES_HH
