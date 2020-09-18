//
// Created by krisv816 on 2019-12-03.
//

#include "Player.h"
#include "Projectile.h"
#include <iostream>
#include <cmath>

Player::Player(double x, double y, sf::Sprite sprite, int hp, int player, sf::Sprite ps)
        :Destroyable{x, y, sprite, hp}
        , RoF{400.0} , speed{0.4}, spawnpoint_x{x}, spawnpoint_y{y}, can_shoot{true}, player_number{player}
        ,currentRoF{RoF}, proj_sprite{ps}
        {}

//Function that handles player movement. It checks which player is trying to move and in which direction.
void Player::movement(sf::Event, sf::Time const& time)
{
    if(player_number == 1) {


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movePlayer(0, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movePlayer(1, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movePlayer(2, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movePlayer(3, time);
        }

    }
    else if(player_number == 2){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            movePlayer(0, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            movePlayer(1, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movePlayer(2, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movePlayer(3, time);
        }
    }
    else if(player_number == 3){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            movePlayer(0, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
            movePlayer(1, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
            movePlayer(2, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            movePlayer(3, time);
        }
    }
    else if(player_number == 4){

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
           movePlayer(0, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) {
            movePlayer(1, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
            movePlayer(2, time);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
            movePlayer(3, time);
        }
    }
}


//Function that handles everything that needs to be updated based on player input. This includes movement and shooting.
//Basically it calls on the movement and shoot function and updates based on the result from those functions.
void Player::update(sf::Event event, std::vector<Object*> &objects, sf::Time const& time)
{
    movement(event, time);
    shoot(event, objects);

    if(!can_shoot)
    {
        reload(time);
    }
}



//Function that handles shooting from players. The first step is to check which player is entering a shoot input.
//After this it checks if a player is allowed to shoot (RoF variable) by checking if the "can_shoot" variable is true.
// Then it checks which direction the player is facing.
// Finally a projectile object gets inserted with the correct rotation in
// the objects vector that keeps track of all objects.

void Player::shoot(sf::Event, std::vector<Object*> &objects)
{
    if(player_number == 1)
    {
        if (can_shoot && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            fireDirection(objects);
        }

    }
    else if(player_number == 2)
    {
        if (can_shoot && sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) {
            fireDirection(objects);
        }
    }
    else if(player_number == 3)
    {
        if (can_shoot && sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            fireDirection(objects);
        }
    }
    else if(player_number == 4)
    {
        if (can_shoot && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) {
            fireDirection(objects);

        }
    }
}


//Function that handles whenever a player object collides with another object. This gets handled through a while loop,
// which will forcefully move the player until it no longer intersects with the object that it had collided with.
void Player::collision(Object* const& o1) {
   while (getSprite().getGlobalBounds().intersects(o1->getSprite().getGlobalBounds()))
    {
       //If player collides with a projectile. Call projectiles collisionhandler.
       if(auto ptr = dynamic_cast<Projectile*>(o1))
       {
           ptr->collision(dynamic_cast<Object*>(this));
           break;
       }

       if(getSprite().getRotation() == 0)
       {
           getSprite().move(0, 1);
       }
       else if(getSprite().getRotation() == 90)
        {
            getSprite().move(-1, 0);
        }
       else if(getSprite().getRotation() == 180)
        {
            getSprite().move(0, -1);
        }
        else if(getSprite().getRotation() == 270)
        {
            getSprite().move(1, 0);
        }
    }
}

double Player::getSpawnpoint_x() const {
    return spawnpoint_x;
}

double Player::getSpawnpoint_y() const {
    return spawnpoint_y;
}
// Function that handles the rate of fire variable by not allowing a player to fire as long as the RoF variable is
//above 0. This can be seen as a cooldown, as the player is allowed to shoot as soon as RoF is at 0 AKA the cooldown is
//finished.
//When a player is allowed to shoot, RoF gets put on cooldown by making it equal to the "currentRoF" variable and the
// "can_shoot" is changed to true.
void Player::reload(sf::Time time)
{
    if(RoF > 0)
    {
        RoF -= time.asMilliseconds();
    }
    else
    {
        RoF = currentRoF;
        can_shoot = true;
    }
}


void Player::fireDirection(std::vector<Object*> &objects)
{
    can_shoot = false;
    sf::Vector2f pos = getSprite().getPosition();
    float rotation = getSprite().getRotation();
    if (rotation == 0) {
        pos.y -= 38;
    } else if (rotation == 90) {
        pos.x += 38;
    } else if (rotation == 180) {
        pos.y += 38;
    } else if (rotation == 270) {
        pos.x -= 38;
    }
    Projectile projectile{pos.x, pos.y, proj_sprite, 1, 1.5};
    projectile.getSprite().setPosition(pos);
    projectile.getSprite().setRotation(rotation);
    objects.push_back(new Projectile{projectile});
}

void Player::movePlayer(int direction, sf::Time time) {
    sf::Vector2f pos = getSprite().getPosition();

    if (direction == 0) {
        getSprite().setRotation(0);
        pos.y = pos.y - speed * time.asMilliseconds();
        getSprite().setPosition(pos);
    } else if (direction == 1) {
        getSprite().setRotation(180);
        pos.y = pos.y + speed * time.asMilliseconds();
        getSprite().setPosition(pos);
    } else if (direction == 2) {
        getSprite().setRotation(270);
        pos.x = pos.x - speed * time.asMilliseconds();
        getSprite().setPosition(pos);
    } else if (direction == 3) {
        getSprite().setRotation(90);
        pos.x = pos.x + speed * time.asMilliseconds();
        getSprite().setPosition(pos);
    }
}


