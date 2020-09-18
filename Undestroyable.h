 //
// Created by johfa464 on 2019-12-05.
//

#ifndef TANKDUELS_UNDESTROYABLE_H
#define TANKDUELS_UNDESTROYABLE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Object.h"

/**
 * Class for undestroyable objects.
 */
class Undestroyable: public Object {
public:
    Undestroyable(double x, double y, sf::Sprite sprite);
    ~Undestroyable() = default;

    /**
     * virtual function that updates objects.
     * @param objects Objects to be updated
     * @param time Makes sure that updating is consistent.
     */
    virtual void update(sf::Event, std::vector<Object*>& objects, sf::Time const& time) override;

    /**
     * virtual function that handles collision
     * @param o1 The Object that is colliding with the current object.
     */
    virtual void collision(Object* const& o1) override;
};


#endif //TANKDUELS_UNDESTROYABLE_H
