#include <SFML/Graphics.hpp>
// #include <SFML/Event.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>
#include <iostream>
#include "Player.h"
#include "Destroyable.h"
#include "Object.h"
#include "DesWall.h"
#include "Base.h"
#include "Undestroyable.h"


int main()
{
    sf::RenderWindow window{sf::VideoMode(1920,1080), "Hello World!"};
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Blue);
    sf::Vector2f v1(300, 300);
    shape.setPosition(v1.x, v1.y);
// Draw it
    sf::Image image;
    image.loadFromFile("images/sfml-icon-small.png");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite player_sprite{};
    player_sprite.setTexture(texture);
    player_sprite.setTextureRect(sf::IntRect(100, 100, 100, 100));
    player_sprite.setPosition(100,100);
    player_sprite.setOrigin(100/2, 100/2);
    Player p1{100.0, 100.0, player_sprite, 1, 1};
    Player p2{200, 200, player_sprite, 1, 2};
    p2.sprite.setColor(sf::Color::Red);
    std::cout << p2.sprite.getRotation() << std::endl;

    sf::Image DesWall_i;
    DesWall_i.loadFromFile("images/DesWall.png");
    sf::Texture DesWall_t;
    DesWall_t.loadFromImage(DesWall_i);
    sf::Sprite DesWall_sprite{};
    DesWall_sprite.setTexture(DesWall_t);
    DesWall_sprite.setPosition(200, 200);
    DesWall wall1{100.0, 100.0, DesWall_sprite, 1};

    sf::Image NonDesWall_i;
    NonDesWall_i.loadFromFile("images/NonDesWall.png");
    sf::Texture NonDesWall_t;
    NonDesWall_t.loadFromImage(NonDesWall_i);
    sf::Sprite NonDesWall_sprite{};
    NonDesWall_sprite.setTexture(NonDesWall_t);
    //NonDesWall_sprite.setTextureRect(sf::IntRect(200, 200, 200, 200));
    NonDesWall_sprite.setPosition(500, 100);
    Undestroyable NonDesWall1{100.0, 100.0, NonDesWall_sprite};

    sf::Image base_i;
    base_i.loadFromFile("images/base.png");
    sf::Texture base_t;
    base_t.loadFromImage(base_i);
    sf::Sprite base_sprite{};
    base_sprite.setTexture(base_t);
    //base_sprite.setTextureRect(sf::IntRect(200, 200, 200, 200));
    base_sprite.setPosition(500, 100);
    base base1{100.0, 100.0, base_sprite, 1, 0};



    while (window.isOpen())
    {
        sf::Event event{};
        bool upPressed = false;
        bool downPressed = false;
        bool leftPressed = false;
        bool rightPressed = false;
        while(window.pollEvent(event))
        {
            upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
            downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
            leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
            p1.movement(event);
            p2.movement(event);
            p1.shoot(event, window);

            if(event.type == sf::Event::Closed)
            {
                window.close();

            }

        }
        // update();
        if(upPressed)
        {
            v1.y = v1.y - 5;
            shape.setPosition(v1);
        }
        else if(downPressed)
        {
            v1.y = v1.y + 5;
            shape.setPosition(v1);
        }
        else if(leftPressed)
        {
            v1.x = v1.x - 5;
            shape.setPosition(v1);
        }
        else if(rightPressed)
        {
            v1.x = v1.x + 5;
            shape.setPosition(v1);
        }
        // std::cout<<shape.getPosition()<<std::endl;
        if (!p1.sprite.getGlobalBounds().intersects(wall1.sprite.getGlobalBounds())) {}
        else {
            std::cout << "Player has collided" << std::endl;
        }
        window.clear();
        window.draw(NonDesWall1.sprite);
        window.draw(p1.sprite);
        window.draw(wall1.sprite);
        window.draw(base1.sprite);
        //p1.draw(window);
        window.draw(p2.sprite);
        window.display();
    }
    return 0;
}
