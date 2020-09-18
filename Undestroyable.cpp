//
// Created by johfa464 on 2019-12-05.
//

#include "Undestroyable.h"

Undestroyable::Undestroyable(double x, double y, sf::Sprite sprite)
:Object{x, y, sprite}
{}

void Undestroyable::update(sf::Event, std::vector<Object *> &objects, sf::Time const& time)
{}

void Undestroyable::collision(Object* const& o1) {

}

