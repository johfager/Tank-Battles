//
// Created by johfa464 on 2019-12-11.
//

#include "Menu.h"
//The things that will be included in the main menu will be created here. This includes the font, what text should be
//shown, color and position.
Menu::Menu(double width, double height) {

    if(!font.loadFromFile("fonts/pixelfont.otf"))
    {
    };
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1)*1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Switch to 2v2");
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1)*2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Switch to 1v1");
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1)*3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS + 1) * 4));


    selected = 0;
}

//Function that handles the printing of the menu screen.
void Menu::draw(sf::RenderWindow &window) const
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}
//Function that handles user input. This specific one moves up.
void Menu::MoveUp()
{
    if (selected - 1 >= 0)
    {
        menu[selected].setColor(sf::Color::White);
        selected--;
        menu[selected].setColor(sf::Color::Red);
    }
}

//Function that handles user input. This specific one moves down.
void Menu::MoveDown()
{
    if (selected + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selected].setColor(sf::Color::White);
        selected++;
        menu[selected].setColor(sf::Color::Red);
    }
}