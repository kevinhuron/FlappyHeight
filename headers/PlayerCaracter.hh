//
// Created by Kévin HURON on 10/04/2017.
//

#ifndef GAME_BIRD_HH
#define GAME_BIRD_HH

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <time.h>
#include <fstream>
#include "Pipes.hh"
#include "Character.hh"
#include "Star.hh"
#include "Logs.hh"

using namespace std;
using namespace sf;

class PlayerCaracter : public Transformable, public Character {

private:
    float y = 300;
    float x = 30;
    float length = 50;
    float width = 50;
    int points = 0;
    float speed = 3.5;
    bool invincible = false;

public:
    SoundBuffer get_point_buffer; // For sound When get point
    SoundBuffer go_up_buffer; // For sound When go up
    SoundBuffer die_buffer; // For sound When die
    Texture yellow_player_texture;
    Texture blue_player_texture;
    Texture green_player_texture;
    Texture red_player_texture;
    Texture invincible_player_texture;
    Texture last_player_texture;
    Sprite player;
    Sound get_point;
    Sound go_up;
    Sound die;

    int load_file();
    void move_player();
    string return_points();
    bool check_collision(Pipes pipes);
    bool over_pipes(Pipes &pipe);
    void reset_player();
    bool catch_star(Star star);

    virtual double GetX() const;
    void SetX(double x);
    virtual double GetY() const;
    void SetY(double y);
    virtual double GetLength() const;
    void SetLength(double newLength);
    virtual double GetWidth() const;
    void SetWidth(double newWidth);
    virtual double GetSpeed() const;
    void SetSpeed(double newSpeed);
    virtual int GetPoints() const;
    void SetPoints(int newPoints);
    virtual bool GetInvincible() const;
    void SetInvincible(bool newState);

};


#endif //GAME_BIRD_HH
