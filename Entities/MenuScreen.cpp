//
// Created by Kévin HURON on 18/04/2017.
//

#include "../headers/MenuScreen.hh"

/**
 * Show the menu screen
 * @param window
 * @param windowWidth
 * @param windowHeight
 * @param font
 * @return
 */
int MenuScreen::Show(RenderWindow &window, int &windowWidth, int &windowHeight, Font &font) {
    sf::Text title("Amazing Flappy 8", font, 80);
    title.setStyle(sf::Text::Bold);
    title.setFillColor(sf::Color::Red);

    Texture textureYellowPlane;
    if (!textureYellowPlane.loadFromFile("RESOURCES/IMG/player_yellow.png")) {
        return(0);
    }
    Sprite spriteYellowPlane(textureYellowPlane);

    Texture textureBluePlane;
    if (!textureBluePlane.loadFromFile("RESOURCES/IMG/player_blue.png")) {
        return(0);
    }
    Sprite spriteBluePlane(textureBluePlane);

    Texture textureRedPlane;
    if (!textureRedPlane.loadFromFile("RESOURCES/IMG/player_red.png")) {
        return(0);
    }
    Sprite spriteRedPlane(textureRedPlane);

    Texture textureGreenPlane;
    if (!textureGreenPlane.loadFromFile("RESOURCES/IMG/player_green.png")) {
        return(0);
    }
    Sprite spriteGreenPlane(textureGreenPlane);

    Texture texturePipe1;
    if (!texturePipe1.loadFromFile("RESOURCES/IMG/pipe_down2.png")) {
        return(0);
    }
    Sprite spritePipe1(texturePipe1);

    Texture texturePipe2;
    if (!texturePipe2.loadFromFile("RESOURCES/IMG/pipe_up2.png")) {
        return(0);
    }
    Sprite spritePipe2(texturePipe2);

    Texture textureStar;
    if (!textureStar.loadFromFile("RESOURCES/IMG/star.png")) {
        return(0);
    }
    Sprite spriteStar(textureStar);
    
    sf::Text explain("Choose your character in the options screen ", font, 40);
    explain.setPosition(30, 150);
    spriteYellowPlane.setPosition(1200, 130);
    spriteBluePlane.setPosition(1300, 130);
    spriteGreenPlane.setPosition(1400, 130);
    spriteRedPlane.setPosition(1500, 130);
    sf::Text explain2("Avoid pipes ", font, 40);
    explain2.setPosition(30, 290);
    spritePipe1.setPosition(350, 230);
    spritePipe2.setPosition(380, 230);
    spritePipe1.setScale(0.14, 0.14);
    spritePipe2.setScale(0.2, 0.2);
    sf::Text explain3("Catch the star to be invincible ", font, 40);
    explain3.setPosition(30, 400);
    spriteStar.setPosition(850, 400);
    sf::Text explain4("Go as far as possible. ", font, 40);
    explain4.setPosition(1000, 400);

    title.setPosition(windowWidth / 2 - title.getGlobalBounds().width / 2, 20);

    const int buttons = 4;

    sf::Text buttons_text[buttons];

    /**
     * Menu BTN
     */
    string str[] = {"Play", "Score", "Options", "Exit"};
    for (int i = 0; i < buttons; i++) {
        buttons_text[i].setFont(font);
        buttons_text[i].setCharacterSize(65);

        buttons_text[i].setString(str[i]);
        buttons_text[i].setPosition(windowWidth / 2 - buttons_text[i].getGlobalBounds().width / 2, 550 + i * 120);
    }

    while (true) {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return(0);
            else if (buttons_text[0].getGlobalBounds().contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                return(1);
            else if (buttons_text[1].getGlobalBounds().contains(mouse) && (event.type == sf::Event::MouseButtonReleased) &&
                       (event.key.code == sf::Mouse::Left))
                return(2);
            else if (buttons_text[2].getGlobalBounds().contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                return(3);
            else if (buttons_text[3].getGlobalBounds().contains(mouse) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                return(0);

        }
        window.clear();

        for (int i = 0; i < buttons; i++) {
            if (buttons_text[i].getGlobalBounds().contains(mouse))
                buttons_text[i].setFillColor(sf::Color::Yellow);
            else
                buttons_text[i].setFillColor(sf::Color::White);
        }

        for (int i = 0; i < buttons; i++) {
            window.draw(buttons_text[i]);
        }
        window.draw(title);
        window.draw(explain);
        window.draw(spriteYellowPlane);
        window.draw(spriteBluePlane);
        window.draw(spriteGreenPlane);
        window.draw(spriteRedPlane);
        window.draw(explain2);
        window.draw(spritePipe1);
        window.draw(spritePipe2);
        window.draw(explain3);
        window.draw(spriteStar);
        window.draw(explain4);
        window.display();
    }
}