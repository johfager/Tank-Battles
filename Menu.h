//
// Created by johfa464 on 2019-12-11.
//
#ifndef TANKDUELS_MENU_H
#define TANKDUELS_MENU_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 4
//Implementation has been made with a basis from the following tutorial on SFML,
// https://www.youtube.com/watch?v=4Vg9d1pjL20
/**
 * Class for the menu screen
 */
class Menu {
public:
    Menu(double width, double height);
    ~Menu() = default;
    /**
     * Draws a main menu to a window.
     * @param window The window to draw to.
     */
    void draw(sf::RenderWindow &window) const;
    /**
     * Moves "selected" one step upwards.
     */
    void MoveUp();
    /**
     * Moves "selected" one step downwards.
     */
    void MoveDown();
    /**
     * @return which item that has been chosen.
     */
    int GetPressedItem() const {
        return selected;
    };

private:
    /**
     * Variable that keeps track of which option in the menu that should be highlighted.
     */
    int selected;
    /**
     * Variable for which font the text should be in.
     */
    sf::Font font;
    /**
     * Variable used for setting positions of each option.
     */
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};


#endif //TANKDUELS_MENU_H
