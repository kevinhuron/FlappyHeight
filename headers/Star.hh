//
// Created by Kévin HURON on 24/04/2017.
//

#ifndef GAME_STAR_HH
#define GAME_STAR_HH

#include <SFML/Graphics.hpp>
#include "Character.hh"
#include "Logs.hh"

using namespace std;
using namespace sf;

class Star : public Transformable, public Character {

private:
    float y;
    float x;
    float length = 50;
    float width = 50;
    float speed = 4.5; // speed of defilement

public:
    Texture texture_star;
    Sprite sprite_star;

    Star(float xx);
    int load_file();
    void rand_star();
    void move_star();

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
};


#endif //GAME_STAR_HH
