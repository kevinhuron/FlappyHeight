//
// Created by Kévin HURON on 18/04/2017.
//

#include "../headers/ScoreScreen.hh"

/**
 * Show the score screen
 * @param window
 * @param windowWidth
 * @param windowHeight
 * @param font
 * @param results
 */
void ScoreScreen::Show(RenderWindow &window, int &windowWidth, int &windowHeight, Font &font, Results &results) {
    sf::Text title("Score info", font, 80);
    title.setStyle(sf::Text::Bold);

    title.setPosition(windowWidth/2-title.getGlobalBounds().width/2, 20);
    title.setFillColor(Color::Red);
    const int buttons = 2;

    sf::Text buttons_text[buttons];

    string str[] = {"Your best score = " + results.return_points(), "Return to menu"};
    for (int i = 0; i < buttons; i++) {
        buttons_text[i].setFont(font);
        buttons_text[i].setCharacterSize(65);

        buttons_text[i].setString(str[i]);
        buttons_text[i].setPosition(windowWidth/2-buttons_text[i].getGlobalBounds().width/2, 250+i*120);
    }

    while (true) {
        sf::Vector2f mouse(sf::Mouse::getPosition(window));
        sf::Event event;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                return;

            else if (buttons_text[1].getGlobalBounds().contains(mouse) && (event.type == sf::Event::MouseButtonReleased) &&
                     (event.key.code == sf::Mouse::Left)) {
                return;
            }
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
        window.display();
    }
}