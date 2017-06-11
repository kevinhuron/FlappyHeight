//
// Created by Kévin HURON on 10/04/2017.
//

#include "../headers/PlayerCaracter.hh"
using namespace std;

/**
 * Load all character files (IMG and SOUNDS)
 * @return int
 */
int PlayerCaracter::load_file()
{
    Logs logs;
    if (!blue_player_texture.loadFromFile("RESOURCES/IMG/player_blue.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : blue_player_texture");
        return -1;
    }


    player.setTexture(blue_player_texture);

    if (!yellow_player_texture.loadFromFile("RESOURCES/IMG/player_yellow.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : yellow_player_texture");
        return -1;
    }

    if (!red_player_texture.loadFromFile("RESOURCES/IMG/player_red.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : red_player_texture");
        return -1;
    }

    if (!green_player_texture.loadFromFile("RESOURCES/IMG/player_green.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : green_player_texture");
        return -1;
    }

    if (!invincible_player_texture.loadFromFile("RESOURCES/IMG/player_invincible.png")) {
        logs.writeErrorLog("ERROR Chargement de la resource : invincible_player_texture");
        return -1;
    }

    if (!get_point_buffer.loadFromFile("RESOURCES/SOUNDS/get_point.ogg")) {
        logs.writeErrorLog("ERROR Chargement de la resource : get_point_buffer");
        return -1;
    }

    get_point.setBuffer(get_point_buffer);

    if (!go_up_buffer.loadFromFile("RESOURCES/SOUNDS/go_up.ogg")) {
        logs.writeErrorLog("ERROR Chargement de la resource : go_up_buffer");
        return -1;
    }

    go_up.setBuffer(go_up_buffer);

    if (!die_buffer.loadFromFile("RESOURCES/SOUNDS/die.ogg")) {
        logs.writeErrorLog("ERROR Chargement de la resource : die_buffer");
        return -1;
    }

    die.setBuffer(die_buffer);

    return 1;
}

/**
 * Move de player
 */
void PlayerCaracter::move_player()
{
    this->SetY(this->GetY() + this->GetSpeed());
    player.setPosition(x, y);
}

/**
 * Get earned points
 * @return points
 */
string PlayerCaracter::return_points()
{
    stringstream points_ss;
    points_ss << points;
    string points_to_view = points_ss.str();
    return points_to_view;
}

/**
 * Check collision with pipes, bottom and top
 * @param pipes
 * @return bool
 */
bool PlayerCaracter::check_collision(Pipes pipes)
{
    // check if the character touch a pipes OR the top or the bottom
    if ((y < pipes.GetY_up() + pipes.GetLength() && y > pipes.GetY_up()) ||
        (y < pipes.GetY_down() + pipes.GetLength() && y > pipes.GetY_down()) ||
        (y + length < pipes.GetY_up() + pipes.GetLength() && y + length > pipes.GetY_up()) ||
        (y + length < pipes.GetY_down() + pipes.GetLength() && y + length > pipes.GetY_down())) {
        // Check if touch a pipes
        if (x + width > pipes.GetX() && x + width < pipes.GetX() + pipes.GetWidth())
            return true;

        if (y <= 55 || y >= 940) // check if touch the TOP or the BOTTOM
            return true;
    }
    return false;
}

/**
 * Check if player catch the star
 * @param star
 * @return bool
 */
bool PlayerCaracter::catch_star(Star star)
{
    if ((y < star.GetY() + star.GetLength() && y > star.GetY()) || (y + length < star.GetY() + star.GetLength() &&
        y + length > star.GetY())) {
        if (x + width > star.GetX() && x + width < star.GetX() + star.GetWidth())
            return true;
    }
    return false;
}

/**
 * Check when character passed over pipes
 * @param pipe
 * @return bool
 */
bool PlayerCaracter::over_pipes(Pipes &pipe)
{
    if (pipe.GetX() <= -200) {
        pipe.SetX(1000);
        this->SetPoints(this->GetPoints() + 1);
        pipe.rand_pipes();
        return true;
    } else
        return false;
}

/**
 * Start and reset the player
 */
void PlayerCaracter::reset_player()
{
    this->SetSpeed(6); // fall down speed
    this->SetY(300);
    this->SetX(30);
    this->SetLength(50);
    this->SetWidth(50);
    this->SetPoints(0);
}

/**
 * Get Player X position
 * @return x
 */
double PlayerCaracter::GetX() const
{
    return this->x;
}

/**
 * Set Player X position
 * @param x
 */
void PlayerCaracter::SetX(double x)
{
    this->x = x;
    this->mynotify();
}

/**
 * Get Player Y position
 * @return y
 */
double PlayerCaracter::GetY() const
{
    return this->y;
}

/**
 * Set Player Y position
 * @param y
 */
void PlayerCaracter::SetY(double y)
{
    this->y = y;
    this->mynotify();
}

/**
 * Get player length
 * @return length
 */
double PlayerCaracter::GetLength() const
{
    return this->length;
}

/**
 * Set player length
 * @param newLength
 */
void PlayerCaracter::SetLength(double newLength)
{
    this->length = newLength;
}

/**
 * Get player width
 * @return width
 */
double PlayerCaracter::GetWidth() const
{
    return this->width;
}

/**
 * Set player width
 * @param newWidth
 */
void PlayerCaracter::SetWidth(double newWidth)
{
    this->width = newWidth;
}

/**
 * Get player speed
 * @return speed
 */
double PlayerCaracter::GetSpeed() const
{
    return this->speed;
}

/**
 * Set player speed
 * @param newSpeed
 */
void PlayerCaracter::SetSpeed(double newSpeed)
{
    this->speed = newSpeed;
    this->mynotify();
}

/**
 * Get player points in game
 * @return points
 */
int PlayerCaracter::GetPoints() const
{
    return this->points;
}

/**
 * Set player points in game
 * @param newPoints
 */
void PlayerCaracter::SetPoints(int newPoints)
{
    this->points = newPoints;
    this->mynotify();
}

/**
 * Get if player is invincible or not
 * @return
 */
bool PlayerCaracter::GetInvincible() const
{
    return this->invincible;
}

/**
 * Set the state of the player (invincible or not)
 * @param newState
 */
void PlayerCaracter::SetInvincible(bool newState)
{
    this->invincible = newState;
    this->mynotify();
}
