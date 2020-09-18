//
// Created by krisv816 on 2019-12-03.
//

#ifndef TDP005_DESTROYABLE_H
#define TDP005_DESTROYABLE_H
#include "Object.h"
#include <SFML/Graphics/Sprite.hpp>

/**
 * Class for all destroyable objects.
 */
class Destroyable: public Object {
public:
    Destroyable(double x, double y, sf::Sprite sprite, int hp);
    ~Destroyable()=default;

    /**
     * Pure virtual function that updates objects.
     * @param objects Objects to be updated
     * @param time Makes sure that updating is consistent.
     */
    void update(sf::Event, std::vector<Object*>& objects, sf::Time const& time) override;

    /**
     *
     * @return true or false if the object is considered "dead".
     */
    bool is_alive() const;

    /**
     * Reduces an objects "hp" variable by 1.
     */
    void decrease_hp();

    /**
     * Increases an objects "hp" variable by 1.
     */
    void increase_hp();

    /**
     * Pure virtual function that handles collision
     * @param o1 The Object that is colliding with the current object.
     */
    void collision(Object* const& o1) override;

protected:
    /**
     * Variable representing health points.
     */
    int hp;
};


#endif //TDP005_DESTROYABLE_H
