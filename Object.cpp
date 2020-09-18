//
// Created by krisv816 on 2019-12-03.
//

#include "Object.h"

Object::Object(double x, double y, sf::Sprite sprite)
:x{x}, y{y}, sprite{sprite}
{}

sf::Sprite &Object::getSprite(){
    return sprite;
}


