//
// Created by krisv816 on 2019-12-03.
//

#include "Destroyable.h"
Destroyable::Destroyable(double x, double y, sf::Sprite sprite, int hp)
:Object{x, y, sprite}, hp{hp}
{}

void Destroyable::update(sf::Event, std::vector<Object *> &objects, sf::Time const& time) {

}
//Function that gets called when an object takes damage.
void Destroyable::decrease_hp()
{
    hp -=1;
}
//Function that gets called when an object increases its hp. It also handles respawning in certain situations.
void Destroyable::increase_hp()
{
    hp +=1;
}

bool Destroyable::is_alive() const{
    return hp > 0;
}

void Destroyable::collision(Object* const& o1) {

}

