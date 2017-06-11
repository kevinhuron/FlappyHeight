//
// Created by Kévin HURON on 10/04/2017.
//

#include "../headers/Game.hh"

/**
 * Constructor
 */
Game::Game()
{
    state = END;
    if (player.load_file() != 1)
        return ;
    if (!font.loadFromFile("RESOURCES/FONTS/kenpixel.ttf"))
        return ;
    if (!background.loadFromFile("RESOURCES/IMG/background.png"))
        return ;
    if (!floor.loadFromFile("RESOURCES/IMG/floor.png"))
        return ;
    if (!topWall.loadFromFile("RESOURCES/IMG/floor3.png"))
        return ;
    if (results.import_file() != 1)
        return ;
    if (!music_game_buffer.loadFromFile("RESOURCES/SOUNDS/sound_music.ogg")) {
        return ;
    }

    music_game.setBuffer(music_game_buffer);

    /**
     * Define Window SIZE
     */
    windowWidth = 1900;
    windowHeight = 1100;

    window.create(VideoMode(windowWidth, windowHeight), "Flappy 8!");
    window.setFramerateLimit(60);
//    window.setKeyRepeatEnabled(false);
    sounds = true;
    state = MENU;
}

/**
 * Switch game STATE
 */
void Game::runGame()
{
    while (state != END) {
        switch (state) {
            case MENU:
                menu();
                break;

            case GAME:
                gameLoop();
                break;

            case GAME_OVER:
                state = GAME;
                gameLoop();
                break;

            case SCORE:
                score();
                break;

            case OPTIONS:
                options();
                break;

            case END:
                break;
        }
    }
}

/**
 * Show the menu SCREEN
 */
void Game::menu()
{
    MenuScreen menuScreen;
    int resultMenu = menuScreen.Show(window, windowWidth, windowHeight, font);
    if (resultMenu == 0)
        state = END;
    else if (resultMenu == 1)
        state = GAME;
    else if (resultMenu == 2)
        state = SCORE;
    else
        state = OPTIONS;
}

/**
 * Show the score SCREEN
 */
void Game::score()
{
    ScoreScreen scoreScreen;
    scoreScreen.Show(window, windowWidth, windowHeight, font, results);
    state = MENU;
}

/**
 * Show the Options SCREEN
 */
void Game::options()
{
    OptionScreen optionScreen;
    bool resultoption = optionScreen.Show(window, windowWidth, windowHeight, font, sounds, player);
    if (!resultoption)
        state = END;
    else
        state = MENU;
}

/**
 * Loop, IN GAME
 */
void Game::gameLoop()
{
    music_game.play();
    Logs logs;
    Clock fpsClock;
    player.reset_player();
    bool colision = false;
    Pipes pipes(800);
    Pipes pipes2(1200);
    Star star(1200);

    background_sprite.setTexture(background);
    Vector2u TextureSizeBackground;
    Vector2u WindowSize;
    /*
     * Set up the background
     */
    TextureSizeBackground = background.getSize();
    WindowSize = window.getSize();
    float ScaleXBack = (float) WindowSize.x / TextureSizeBackground.x;
    float ScaleYBack = (float) WindowSize.y / TextureSizeBackground.y;
    background_sprite.setScale(ScaleXBack, ScaleYBack);

    /*
     * Set up the bottom floor
     */
    floor_sprite.setTexture(floor);
    floor_sprite.setPosition(0, windowHeight - 130);

    /*
     * Set up the top floor
     */
    top_floor_sprite.setTexture(topWall);

    pipes.rand_pipes();
    pipes2.rand_pipes();
//    star.rand_star();
    textScore.setFont(font);
    textScore.setCharacterSize(50);
    textScore.setPosition(windowWidth / 2 - textScore.getGlobalBounds().width / 2, 50);
    /*
     * the die msg
     */
    FloatRect backgroundRect = error.getLocalBounds();
    RectangleShape background(Vector2f(backgroundRect.width, backgroundRect.height + 15));
    error.setFont(font);
    error.setPosition(40, 200);
    error.setCharacterSize(80);
    error.setFillColor(Color::Red);
    if (pipes.load_file() != 1)
        state = END;
    if (pipes2.load_file() != 1)
        state = END;
    if (results.import_file() != 1)
        state = END;
    if (star.load_file() != 1)
        state = END;
    /*
     * TimeInGame
     */
    Clock TimeInGame;
    Time elapsed2;
    Time elapsed = TimeInGame.getElapsedTime();
    int time2 = elapsed.asMilliseconds() + 5000; // Begin at 5 sec for time 2 for the check (5000 milliseconds)
    int time3 = elapsed.asMilliseconds() + 10000; // 10 sec for time 3 for the check (10000 milliseconds)

    while (state == GAME) {

        /*
         * GET FPS
         */
        // TODO : TRY TO USE OUR TIMEMANAGER
        Time time = fpsClock.getElapsedTime();
        int intFPS = 1.0f / time.asSeconds();
        fpsClock.restart().asSeconds();
        string fps = to_string(intFPS);
        Text fpsText(" FPS : " + fps, font, 30);
        fpsText.setFillColor(Color::Black);

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                if (player.GetSpeed() != 0) {
                    double yPos = player.GetY();
                    player.SetY(yPos - 90);
                    if (sounds) player.go_up.play();
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Return) && player.GetSpeed() == 0)
                state = GAME_OVER;
            else if (Keyboard::isKeyPressed(Keyboard::Escape) && player.GetSpeed() == 0)
                state = MENU;
        }

        if (player.over_pipes(pipes))
            if (sounds) player.get_point.play();

        if (player.over_pipes(pipes2))
            if (sounds) player.get_point.play();

        /*
         * Check if player catch the star
         */
        if (player.catch_star(star)) {
//            player.last_player_texture = player.player.getTexture();
            star.rand_star();
            player.player.setTexture(player.invincible_player_texture);
            player.SetInvincible(true);

            logs.writeLog("Player catch star and get Invincible");
//            player.player.setTexture(player.blue_player_texture);
        }

        /*
         * Check if player is invincible
         */
        if (!player.GetInvincible()) {
            /*
             * Check if collision
             */
            if (player.check_collision(pipes) == true || player.check_collision(pipes2) == true) {
                logs.writeLog("Player get collision with a pipe");
                music_game.stop();
                player.SetSpeed(0);
                pipes.SetSpeed(0);
                pipes2.SetSpeed(0);
                star.SetSpeed(0);
                if (!colision) {
                    colision = true;
                    if (sounds) player.die.play();
                }
                if (results.check(player.GetPoints()))
                    results.save();

                background.setFillColor(Color::White);
                error.setString("You lost! Earned points: " + player.return_points() + "\n" +
                                "Your best score: " + results.return_points() + " points" + "\n" +
                                "If you want play again press ENTER \n" +
                                "Press ESC for back to menu.");
                logs.writeLog("Player loose : his result is " + player.return_points());
            } else {
                background.setFillColor(Color::Transparent);
                error.setString("");
            }
        }

        /*
         * Get The time in game
         */
        elapsed2 = TimeInGame.getElapsedTime();
        int time1 = elapsed2.asMilliseconds();

        /*
         * Accelerate the Game every 5 sec
         */
        if (time1 >= time2) {
            star.SetSpeed(star.GetSpeed() + 1);
            pipes.SetSpeed(pipes.GetSpeed() + 2);
            pipes2.SetSpeed(pipes2.GetSpeed() + 2);
            player.SetSpeed(player.GetSpeed() + 2);
            time2 = time2 + 5000;
            logs.writeLog("Acceleration of the game");
        }

        /*
         * Check every 10 sec if player is invincible so reset the player
         */
        if (time1 >= time3) {
            if (player.GetInvincible()) {
                player.SetInvincible(false);
                player.player.setTexture(player.blue_player_texture);
                logs.writeLog("Player loose the invincible status");
            }
            time3 = time3 + 10000;
        }

        /*
         * Check if star got out the screen, then reset a random star
         */
        if (star.GetX() <= 0) {
            star.rand_star();
        }

        textScore.setString(player.return_points());
        textScore.setFillColor(Color::Black);
        player.move_player();
        pipes.move_pipes();
        pipes2.move_pipes();
        star.move_star();
        window.clear();
        window.draw(background_sprite);
        window.draw(star.sprite_star);
        window.draw(pipes.pipe_down);
        window.draw(pipes2.pipe_down);
        window.draw(floor_sprite);
        window.draw(top_floor_sprite);
        window.draw(pipes.pipe_up);
        window.draw(pipes2.pipe_up);
        window.draw(fpsText);
        window.draw(textScore);
        window.draw(player.player);
        window.draw(background, error.getTransform()); // Adjust the white background error text to the error text
        window.draw(error);
        window.display();
    }
}