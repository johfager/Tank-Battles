//
// Created by johfa464 on 2019-12-11.
//

#include "run.h"

void Run::run() {
    sf::RenderWindow window{sf::VideoMode(1920,1080), "Hello World!"};
    window.setKeyRepeatEnabled(true);
    window.setVerticalSyncEnabled(true);
    std::vector<Object*> objects{};
    sf::Clock clock;

    PlayState PS{};

    std::map<std::string, sf::Texture*> texture = PS.create_textures();
    std::map<std::string, sf::Sprite> sprites = PS.create_sprites(texture);
    std::string line;

    double y{0};
    std::ifstream ifs{"arenas/arena1.txt"};
    while(getline(ifs, line))
    {
        double x{0};
        for(char c: line)
        {
            if (c == '#')
            {
                Undestroyable NonDesWall{ x, y, sprites["NonDesWall"]};
                NonDesWall.sprite.setPosition(x, y);
                objects.push_back(new Undestroyable{NonDesWall});
            }
            else if(c == 'H')
            {
                DesWall Des_Wall{x, y, sprites["DesWall"], 1};
                Des_Wall.sprite.setPosition(x, y);
                objects.push_back(new DesWall{Des_Wall});
            }
            else if(c == 'B')
            {
                base Base{x, y, sprites["Base"], 1, 0};
                Base.sprite.setPosition(x, y);
                objects.push_back(new base{Base});
            }

            else if(c == '1')
            {
                Player p1{x, y, sprites["Player"], 1, 1, sprites["Projectile"]};
                p1.sprite.setPosition(x, y);
                objects.push_back(new Player{p1});

            }
            else if(c == '2')
            {
                Player p2{x, y, sprites["Player"], 1, 2, sprites["Projectile"]};
                p2.sprite.setPosition(x, y);
                objects.push_back(new Player{p2});
            }
            x += 50;
        }
        y += 50;
    }

    m_machine.run( StateMachine::build<IntroState>( m_machine, m_window, true ) );

    // Main loop
    while(m_machine.running()) {
        m_machine.nextState();
        m_machine.update();
        m_machine.draw();
    }
}
