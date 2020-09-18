//
// Created by krisv816 on 2019-12-09.
//

#include "Projectile.h"
#include "Undestroyable.h"

Projectile::Projectile(double x, double y, sf::Sprite s, int hp, double speed)
: Destroyable(x, y, s, hp), speed{speed}
{}

//Function that updates a projectile objects movement by calling the move function.
void Projectile::update(sf::Event event, std::vector<Object *> &objects, sf::Time const& time) {
   move(time);
}

//A movement function that moves a projectile object by checking its rotation, moving it
// and then setting its position based on where it has moved.
void Projectile::move(sf::Time const& time)
{
    sf::Vector2f pos = getSprite().getPosition();
    float rotation = getSprite().getRotation();
    if(rotation == 0)
    {
        pos.y -= speed * time.asMilliseconds();
    }
    else if(rotation == 90)
    {
        pos.x += speed * time.asMilliseconds();
    }
    else if(rotation == 180)
    {
        pos.y += speed * time.asMilliseconds();
    }
    else if(rotation == 270)
    {
        pos.x -= speed * time.asMilliseconds();
    }
    getSprite().setPosition(pos);
}

//The result of When a projectile object collides with another object in this game is that both objects takes 1 "damage"
// to their hp. This is done by calling the "decrease_hp" function for all objects affected. This doesnt apply
//when a projectile collides with an undestroyable object where only the projectile will take damage instead.
void Projectile::collision(Object* const& o1)
{
    if(getSprite().getGlobalBounds().intersects(o1->getSprite().getGlobalBounds()))
    {
        if(auto ptr = dynamic_cast<Destroyable*>(o1))
        {
            ptr -> decrease_hp();
            decrease_hp();
        }
        else if(auto ptr2 = dynamic_cast<const Undestroyable*>(o1))
        {
            decrease_hp();
        }
    }
}
