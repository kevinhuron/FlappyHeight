//
// Created by Kévin HURON on 10/04/2017.
//

#include "../headers/Pipes.hh"
using namespace std;

/**
 * Constructor
 * @param xx
 */
Pipes::Pipes(float xx)
{
    x = xx;
}

/**
 * Load pipes img
 * @return
 */
int Pipes::load_file()
{
    Logs logs;
    if (!texture_up_pipe.loadFromFile("RESOURCES/IMG/pipe_up2.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : texture_up_pipe");
        return -1;
    }
    pipe_up.setTexture(texture_up_pipe);

    if (!texture_down_pipe.loadFromFile("RESOURCES/IMG/pipe_down2.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : texture_down_pipe");
        return -1;
    }
    pipe_down.setTexture(texture_down_pipe);
    return 1;
}

/**
 * Set Random pipies
 */
void Pipes::rand_pipes()
{
    this->y_up = (rand() % (150+free_space)) - (150+free_space);
    this->y_down = y_up + pipe_len + free_space;
}

/**
 * Move pipes
 */
void Pipes::move_pipes()
{
    x-=speed;
    pipe_up.setPosition(x, y_up);
    pipe_down.setPosition(x, y_down);
}

/**
 * Get Pipe X position
 * @return x
 */
double Pipes::GetX() const
{
    return this->x;
}

/**
 * Set Pipe X position
 * @param x
 */
void Pipes::SetX(double x)
{
    this->x = x;
    this->mynotify();
}

/**
 * Get Pipe Y_up position
 * @return y_up
 */
double Pipes::GetY_up() const
{
    return this->y_up;
}

/**
 * Set Pipe Y_up position
 * @param newY_up
 */
void Pipes::SetY_up(double newY_up)
{
    this->y_up = newY_up;
    this->mynotify();
}

/**
 * Get Pipe Y_down position
 * @return y_down
 */
double Pipes::GetY_down() const
{
    return this->y_down;
}

/**
 * Set Pipe Y_down position
 * @param newY_down
 */
void Pipes::SetY_down(double newY_down)
{
    this->y_down = newY_down;
    this->mynotify();
}

/**
 * Get Pipe Speed
 * @return speed
 */
double Pipes::GetSpeed() const
{
    return this->speed;
}

/**
 * Set Pipe Speed
 * @param newSpeed
 */
void Pipes::SetSpeed(double newSpeed)
{
    this->speed = newSpeed;
}

/**
 * Get Pipe Length
 * @return pipe_len
 */
double Pipes::GetLength() const
{
    return this->pipe_len;
}

/**
 * Set Pipe Length
 * @param newLength
 */
void Pipes::SetLength(double newLength)
{
    this->pipe_len = newLength;
}

/**
 * Get Pipe Width
 * @return pipe_width
 */
double Pipes::GetWidth() const
{
    return this->pipe_width;
}

/**
 * Set Pipe Width
 * @param newWidth
 */
void Pipes::SetWidth(double newWidth)
{
    this->pipe_width = newWidth;
}

/**
 * Get Pipe Free Space
 * @return free_space
 */
int Pipes::GetFreeSpace() const
{
    return this->free_space;
}

/**
 * Set Pipe Free Space
 * @param newFreeSpace
 */
void Pipes::SetFreeSpace(int newFreeSpace)
{
    this->free_space = newFreeSpace;
}