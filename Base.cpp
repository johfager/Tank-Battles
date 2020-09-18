//
// Created by johfa464 on 2019-12-04.
//

#include "Base.h"

Base::Base(double x, double y, sf::Sprite sprite, int hp, int team)
: Destroyable(x, y, sprite, hp), team{team}
{}

int Base::getTeam() const
{
    return team;
}