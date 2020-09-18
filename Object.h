//
// Created by krisv816 on 2019-12-03.
//

#ifndef TANKDUELS_OBJECT_H
#define TANKDUELS_OBJECT_H
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

/**
 * Base class for all objects in the game.
 */
class Object {
public:
    Object(double x, double y, sf::Sprite sprite);
    virtual ~Object()=default;

    /**
     * Pure virtual function that updates objects.
     * @param objects Objects to be updated
     * @param time Makes sure that updating is consistent.
     */
    virtual void update(sf::Event, std::vector<Object*>& objects, sf::Time const& time) = 0;
    /**
     * Pure virtual function that handles collision
     * @param o1 The Object that is colliding with the current object.
     */
    virtual void collision(Object* const& o1) = 0;
    /**
     * @return the object's sprite.
     */
    sf::Sprite& getSprite();
private:

    /**
     * X-coordinate
     */
    double x;
    /**
     * Y-coordinate
     */
    double y;

    /**
     * Sprite of the object.
    */
    sf::Sprite sprite;

};


#endif //TANKDUELS_OBJECT_H
