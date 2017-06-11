//
// Created by Kévin HURON on 24/04/2017.
//

#include "../headers/Star.hh"

Star::Star(float xx)
{
//    this->x = xx;
}

/**
 * load star img
 * @return int
 */
int Star::load_file()
{
    Logs logs;
    if (!texture_star.loadFromFile("RESOURCES/IMG/star.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : texture_star");
        return -1;
    }
    sprite_star.setTexture(texture_star);

    return 1;
}

/**
 * Random Star
 */
void Star::rand_star()
{
    this->x = (rand() % (1500));
    this->y = (rand() % (1000) + length);
}

/**
 * Move the start
 */
void Star::move_star()
{
    x-=speed;
    this->sprite_star.setPosition(this->x, this->y);
}

/**
 * Get Star X position
 * @return x
 */
double Star::GetX() const
{
    return this->x;
}

/**
 * Set Star X position
 * @param x
 */
void Star::SetX(double x)
{
    this->x = x;
    this->mynotify();
}

/**
 * Get Star Y position
 * @return
 */
double Star::GetY() const
{
    return this->y;
}

/**
 * Set Star Y position
 * @param y
 */
void Star::SetY(double y)
{
    this->y = y;
    this->mynotify();
}

/**
 * Get Star length
 * @return length
 */
double Star::GetLength() const
{
    return this->length;
}

/**
 * Set Star length
 * @param newLength
 */
void Star::SetLength(double newLength)
{
    this->length = newLength;
    this->mynotify();
}

/**
 * Get Star Width
 * @return width
 */
double Star::GetWidth() const
{
    return this->width;
}

/**
 * Set Star Width
 * @param newWidth
 */
void Star::SetWidth(double newWidth)
{
    this->width = newWidth;
    this->mynotify();
}

/**
 * Get Star Speed
 * @return speed
 */
double Star::GetSpeed() const
{
    return this->speed;
}

/**
 * Set Star Speed
 * @param newSpeed
 */
void Star::SetSpeed(double newSpeed)
{
    this->speed = newSpeed;
}