//
// Created by johfa464 on 2019-12-04.
//

#ifndef TANKDUELS_DESWALL_H
#define TANKDUELS_DESWALL_H
#include "Destroyable.h"
#include <SFML/Graphics/Sprite.hpp>

/**
 * Class representing destroyable walls.
 */
class DesWall: public Destroyable {
public:
    DesWall(double x, double y, sf::Sprite sprite, int hp);
    ~DesWall() = default;

};


#endif //TANKDUELS_DESWALL_H
