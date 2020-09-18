//
// Created by krisv816 on 2019-12-11.
//

#ifndef TANKDUELS_GAME_H
#define TANKDUELS_GAME_H
#include <SFML/Graphics.hpp>
// #include <SFML/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Destroyable.h"
#include "Object.h"
#include "DesWall.h"
#include "Base.h"
#include "Projectile.h"
#include "Undestroyable.h"
#include "PlayState.h"
#include "Menu.h"

/**
 * Responsible for running the game.
 */
class Game {
public:
    Game(std::string filepath = "arenas/arena1v1.txt");
    ~Game() = default;

    /**
     * Creates and handles the necessary components for starting and running the game.
     */
    void run();

private:

    /**
     * Creates a menu screen, based on the menu parameter.
     * @param window The window to draw to.
     * @param menu menu object containing what should be drawn.
     */
    void main_menu(sf::RenderWindow &window, Menu & menu);


    /**
     * Resets the stage and scores, empties the vector and goes to the menu screen.
     * @param window The window to draw to.
     * @param menu menu object containing what should be drawn.
     */
    void goToMenu(sf::RenderWindow &window, Menu & menu);

    /**
     * Changes gamemode.
     */
    void changeGameMode();

    PlayState PS{};

    /**
     * Integer representing what gamemode that should be run.
     */
    int gameMode;
};


#endif //TANKDUELS_GAME_H
