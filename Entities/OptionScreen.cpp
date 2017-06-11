//
// Created by Kévin HURON on 18/04/2017.
//

#include "../headers/OptionScreen.hh"

/**
 * Show the Options screen
 * @param window
 * @param windowWidth
 * @param windowHeight
 * @param font
 * @param sounds
 * @param player
 * @return
 */
bool OptionScreen::Show(RenderWindow &window, int &windowWidth, int &windowHeight, Font &font, bool &sounds, PlayerCaracter &player) {
    TimeManager::GetInstance().Start();
    TimeManager::GetInstance().Update();

    Text title("Options", font, 60);
    title.setStyle(sf::Text::Bold);

    /**
     * The yellow plane
     */
    Texture yellow_player_texture;
    IntRect rectYellow_player_texture(0, 290, 88, 73);
//    IntRect rectYellow_player_texture(0, 217, 88, 73);
//    IntRect rectYellow_player_texture(0, 144, 88, 73);
    if (!yellow_player_texture.loadFromFile("RESOURCES/IMG/planes.png")) {
        return(0);
    }
    Sprite yellow_player(yellow_player_texture, rectYellow_player_texture);

    /**
     * The blue plane
     */
    Texture blue_player_texture;
    IntRect rectBlue_player_texture(0, 73, 88, 73);
//    IntRect rectBlue_player_texture(0, 0, 88, 73);
//    IntRect rectBlue_player_texture(0, 365, 88, 73);
    if (!blue_player_texture.loadFromFile("RESOURCES/IMG/planes.png")) {
        return(0);
    }
    Sprite blue_player(blue_player_texture, rectBlue_player_texture);

    /**
     * The red plane
     */
    Texture red_player_texture;
    IntRect rectRed_player_texture(87, 0, 88, 73);
//    IntRect rectRed_player_texture(0, 437, 88, 73);
//    IntRect rectRed_player_texture(87, 290, 88, 73);
    if (!red_player_texture.loadFromFile("RESOURCES/IMG/planes.png")) {
        return(0);
    }
    Sprite red_player(red_player_texture, rectRed_player_texture);

    /**
     * The green plane
     */
    Texture green_player_texture;
//    IntRect rectGreen_player_texture(87, 72, 88, 73);
//    IntRect rectGreen_player_texture(87, 145, 88, 73);
    IntRect rectGreen_player_texture(87, 218, 88, 73);
    if (!green_player_texture.loadFromFile("RESOURCES/IMG/planes.png")) {
        return(0);
    }
    Sprite green_player(green_player_texture, rectGreen_player_texture);

    yellow_player.setPosition(630, 250);
    blue_player.setPosition(1100, 250);
    green_player.setPosition(630, 450);
    red_player.setPosition(1100, 450);

    title.setPosition(windowWidth/2-title.getGlobalBounds().width/2, 20);
    title.setFillColor(Color::Red);

    const int buttons = 6; // how much buttons

    sf::Text buttons_text[buttons];

    /**
     * Options btn
     */
    string str[] = {"Yellow Player" , "Blue Player", "Green Player", "Red Player", "Return to menu", "Sounds: ON"};
    for (int i = 0; i < buttons; i++) {
        buttons_text[i].setFont(font);
        buttons_text[i].setCharacterSize(40);
        buttons_text[i].setString(str[i]);
    }
    /**
     * set plane position
     */
    buttons_text[0].setPosition(500, 150);
    buttons_text[1].setPosition(1000, 150);
    buttons_text[2].setPosition(500, 350);
    buttons_text[3].setPosition(1000, 350);

    buttons_text[4].setCharacterSize(70);
    buttons_text[4].setPosition(windowWidth/2-buttons_text[4].getGlobalBounds().width/2, 900);
    buttons_text[5].setCharacterSize(70);
    buttons_text[5].setPosition(windowWidth/2-buttons_text[5].getGlobalBounds().width/2, 700);

    if (sounds) {
        buttons_text[5].setFillColor(sf::Color::Green);
        buttons_text[5].setString("Sounds: ON");
    } else {
        buttons_text[5].setFillColor(sf::Color::Red);
        buttons_text[5].setString("Sounds: OFF");
    }

    while (true) {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));
        sf::Event event;

        /**
         * Animate planes logo WITH OUR TIMEMANAGER
         */
        if (TimeManager::GetInstance().GetElapsedTime() > 16) {
            /**
             * Blue plane
             */
            if (rectBlue_player_texture.top == 73)
                rectBlue_player_texture.top = 0;
            else if (rectBlue_player_texture.top == 365)
                rectBlue_player_texture.top = 73;
            else if (rectBlue_player_texture.top == 0)
                rectBlue_player_texture.top = 365;
            /**
             * Yellow plane
             */
            if (rectYellow_player_texture.top == 290)
                rectYellow_player_texture.top = 217;
            else if (rectYellow_player_texture.top == 144)
                rectYellow_player_texture.top = 290;
            else if (rectYellow_player_texture.top == 217)
                rectYellow_player_texture.top = 144;
            /**
             * Green plane
             */
            if (rectGreen_player_texture.top == 218)
                rectGreen_player_texture.top = 145;
            else if (rectGreen_player_texture.top == 72)
                rectGreen_player_texture.top = 218;
            else if (rectGreen_player_texture.top == 145)
                rectGreen_player_texture.top = 72;
            /**
             * Red plane
             */
            if (rectRed_player_texture.top == 0 && rectRed_player_texture.left == 87) {
                rectRed_player_texture.left = 0;
                rectRed_player_texture.top = 437;
            } else if (rectRed_player_texture.top == 290 && rectRed_player_texture.left == 87) {
                rectRed_player_texture.top = 0;
                rectRed_player_texture.left = 87;
            } else if (rectRed_player_texture.left == 0 && rectRed_player_texture.top == 437) {
                rectRed_player_texture.top = 290;
                rectRed_player_texture.left = 87;
            }

            blue_player.setTextureRect(rectBlue_player_texture);
            yellow_player.setTextureRect(rectYellow_player_texture);
            green_player.setTextureRect(rectGreen_player_texture);
            red_player.setTextureRect(rectRed_player_texture);
            TimeManager::GetInstance().Update();
        }
        TimeManager::GetInstance().Update();

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return(1);
                /**
                 * Check if user choose a plane or switch sound ON / OFF
                 * Then save the setting
                 */
            else if ((buttons_text[0].getGlobalBounds().contains(mouse) || yellow_player.getGlobalBounds().contains(mouse)) &&
                     (event.type == sf::Event::MouseButtonReleased) &&
                     (event.key.code == sf::Mouse::Left)) {
                player.player.setTexture(player.yellow_player_texture);

            } else if ((buttons_text[1].getGlobalBounds().contains(mouse) || blue_player.getGlobalBounds().contains(mouse)) &&
                       (event.type == sf::Event::MouseButtonReleased) &&
                       (event.key.code == sf::Mouse::Left)) {
                player.player.setTexture(player.blue_player_texture);

            } else if ((buttons_text[2].getGlobalBounds().contains(mouse) || green_player.getGlobalBounds().contains(mouse)) &&
                       (event.type == sf::Event::MouseButtonReleased) &&
                       (event.key.code == sf::Mouse::Left)) {
                player.player.setTexture(player.green_player_texture);

            } else if ((buttons_text[3].getGlobalBounds().contains(mouse) || red_player.getGlobalBounds().contains(mouse)) &&
                       (event.type == sf::Event::MouseButtonReleased) &&
                       (event.key.code == sf::Mouse::Left)) {
                player.player.setTexture(player.red_player_texture);

            } else if ((buttons_text[4].getGlobalBounds().contains(mouse)) &&
                       (event.type == sf::Event::MouseButtonReleased) &&
                       (event.key.code == sf::Mouse::Left)) {
                return (1);
            } else if ((buttons_text[5].getGlobalBounds().contains(mouse)) &&
                       event.type == sf::Event::MouseButtonReleased &&
                       event.key.code == sf::Mouse::Left) {
                if (sounds) {
                    buttons_text[5].setString("Sounds: OFF");
                    buttons_text[5].setFillColor(sf::Color::Red);
                    sounds = false;
                } else {
                    buttons_text[5].setString("Sounds: ON");
                    buttons_text[5].setFillColor(sf::Color::Green);
                    sounds = true;
                }
            }
        }
        window.clear();

        for (int i = 0; i < buttons - 1; i++) { // -1 because the SOUNDS button is collored above
            if (buttons_text[i].getGlobalBounds().contains(mouse))
                buttons_text[i].setFillColor(sf::Color::Yellow);
            else
                buttons_text[i].setFillColor(sf::Color::White);
        }

        for (int i = 0; i<buttons; i++) {
            window.draw(buttons_text[i]);
        }
        window.draw(title);
        window.draw(yellow_player);
        window.draw(blue_player);
        window.draw(green_player);
        window.draw(red_player);
        window.display();
    }
}