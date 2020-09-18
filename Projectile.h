//
// Created by krisv816 on 2019-12-09.
//

#ifndef TANKDUELS_PROJECTILE_H
#define TANKDUELS_PROJECTILE_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Destroyable.h"


/**
 * class that represents Projectile objects.
 */
class Projectile: public Destroyable {
public:
    Projectile(double x, double y, sf::Sprite s, int hp, double speed);

    /**
    * function that updates the projectile object.
    * @param objects Objects that the projectile object interacts with.
    * @param time Makes sure that updating is consistent.
    */
    void update(sf::Event event, std::vector<Object*>& objects, sf::Time const& time) override;

    /**
     * Moves the projectile
     * @param time Makes sure that the movement is consistent each tick.
     */
    void move(sf::Time const& time);

    /**
     * function that handles the projectiles collisions.
     * @param o1 The Object that is colliding with the current projectile.
     */
    void collision(Object* const& o1) override;

private:

    /**
    * Variable for how much distance a player object can move.
    */
double speed;


};


#endif //TANKDUELS_PROJECTILE_H
