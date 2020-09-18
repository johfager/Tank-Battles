//
// Created by johfa464 on 2019-12-09.
//

#ifndef TANKDUELS_PLAYSTATE_H
#define TANKDUELS_PLAYSTATE_H
#include "Object.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <fstream>

#include "Player.h"
#include "Destroyable.h"
#include "Object.h"
#include "DesWall.h"
#include "Base.h"
#include "Projectile.h"
#include "Undestroyable.h"
#include "Menu.h"
/**
 * Represents the "PlayState" of the program.
 */
class PlayState {
public:
    PlayState (std::string filepath = "arenas/arena1v1.txt");
    ~PlayState();

    /**
     * Updates all objects in the vector "objects".
     * @param event input from the user
     * @param objects all the objects present in the game.
     * @param time Makes sure updating is consistent.
     * @param roundOver Variable in charge of checking if a round is over.
     * @param scoreOne Score of team one.
     * @param scoreTwo Score of team two.
     */
    void update(sf::Event const& event, sf::Time time);

    /**
     * Draws objects to a window.
     * @param objects Vector of objects.
     * @param window Window to be drawn to.
     */
    void draw(sf::RenderTarget& window) const;

    /**
     * Deletes objects from a vector.
     * @param objects Vector of objects.
     */
    void removeFromBoard();

    /**
     * Fills the vector "objects" with game-objects based on symbols from a text-file.
    */
    void make_arena();

    /**
     * Fills the map "sprites" with sprites as values and their name as the keys.
     */
    void create_sprites();

    /**
     * Fills the map "textures" with textures as values and their name as the keys.
     */
    void create_textures();

    /**
  * Resets the arena after a round is over.
  */
    void emptyBoard();

    /**
  * Resets "scoreOne" and "scoreTwo" to 0.
  */
    void resetScore();

    /**
     * Sets the filepath.
     * @param newPath
     */
    void setFilepath(std::string newPath);
    /**
     * Checks if a team has won a match.
     * @return true if either score one or two is 3
     */
    bool hasWon() const;

    /**
     * Returns a string based on which team has won.
     * @return a string.
     */
    std::string getWinner() const;

    /**
     * Draws a scoreboard.
     * @param window The window to draw to.
     */
    void draw_scoreboard(sf::RenderWindow &window) const;

    /**
     * Checks if a round is over.
     */
    void isRoundOver();

private:
    /**
    * Map containing textures as values and their name as keys.
    */
    std::map<std::string, sf::Texture*> textures;
    /**
     * Map containing sprites as values and their name as keys.
     */
    std::map<std::string, sf::Sprite> sprites;
    /**
     * Vector containing Objects* to game objects.
     */
    std::vector<Object*> objects{};
    /**
     * The score for team one.
     */
    int scoreOne;
    /**
     * The score for team two.
     */
    int scoreTwo;

    /**
 *String containing the filepath for reading an arena.
 */
    std::string filepath;

    /**
     * Is true when a base has been destroyed.
     */
    bool roundOver;
};


#endif //TANKDUELS_PLAYSTATE_H
