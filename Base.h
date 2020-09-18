//
// Created by johfa464 on 2019-12-04.
//

#ifndef TANKDUELS_BASE_H
#define TANKDUELS_BASE_H

#include "SFML/Graphics.hpp"
#include "Destroyable.h"



/**
 * Class representing base objects.
 */
class Base: public Destroyable {
public:
    Base(double x, double y, sf::Sprite sprite, int hp, int team);
    ~Base() = default;

    /**
     *
     * @return a number representing a team.
     */
    int getTeam() const;

private:
    /**
     * Variable representing a team.
     */
    int team{};

};


#endif //TANKDUELS_BASE_H
