//
// Created by krisv816 on 2019-12-03.
//

#ifndef TANKDUELS_PLAYER_H
#define TANKDUELS_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <vector>
#include "Destroyable.h"
#include "Projectile.h"



/**
 * Class that represents player objects.
 */
class Player: public Destroyable{
public:
    Player(double x, double y, sf::Sprite sprite, int hp, int player, sf::Sprite ps);
    ~Player() = default;

    /**
     * Moves the player object based on input.
     * @param time Makes sure that movement is consistent.
     */
    void movement(sf::Event, sf::Time const& time);

    /**
     * function that updates the player object.
     * @param objects Objects that the player object interacts with.
     * @param time Makes sure that updating is consistent.
     */
    void update(sf::Event event, std::vector<Object*>& objects, sf::Time const& time) override;

    /**
     * Spawns projectile objects in front of the player object.
     * @param objects The vector which projectile objects will be inserted into.
     */
    void shoot(sf::Event, std::vector<Object*> &objects);

    /**
     * function that handles the players collisions.
     * @param o1 The Object that is colliding with the current player.
     */
    void collision(Object* const& o1) override;

    /**
     *
     * @return players spawnpoint_x variable.
     */
    double getSpawnpoint_x() const;

    /**
     *
     * @return players spawnpoint_y variable.
     */
    double getSpawnpoint_y() const;


private:

    /**
     * Updates the player object's ability to spawn projectile objects.
     * @param time Makes sure that the updating is consistent.
     */
    void reload(sf::Time time);

    /**
     * Spawns a projectile object in front of the player, taking into consideration the player object's rotational direction.
     * @param objects The vector where projectile objects gets inserted into.
     */
    void fireDirection(std::vector<Object*> &objects);

    /**
     * Moves the player in the correct direction.
     * @param direction Keeps track of a direction.
     * @param time Makes sure that the updating of the player object is consistent.
     */
    void movePlayer(int direction, sf::Time time);

    /**
    * X-coordinate for the player's spawn point.
    */
    double const spawnpoint_x;

    /**
    * Y-coordinate for the player's spawn point.
    */
    double const spawnpoint_y;

    /**
     * Variable for the player's rate of fire.
     */
    double RoF;

    /**
     * Variable for how much distance a player object can move.
     */
    double speed;


    /**
     * Variable keeping track of the player object and if it is allowed to shoot.
     */
    bool can_shoot;


    /**
     * Variable for a player object's individual number.
     */
    int player_number;


    /**
     * Keeps track of the variable "RoF" original value.
     */
    double currentRoF;


    /**
     * Sprite for projectile objects.
     */
    sf::Sprite proj_sprite;


};


#endif //TANKDUELS_PLAYER_H
