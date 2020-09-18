//
// Created by johfa464 on 2019-12-09.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Destroyable.h"
#include "Object.h"

#include "Base.h"
#include "PlayState.h"

#include <algorithm>

PlayState::PlayState(std::string filepath)
:scoreOne{0}, scoreTwo{0}, filepath{filepath}, roundOver{false}
{
    create_textures();
    create_sprites();
}

PlayState::~PlayState(){
    for(auto o: objects)
    {
        delete o;
        o = nullptr;
    }
    for(auto p: textures)
    {
        delete p.second;
        p.second = nullptr;
    }
}

void PlayState::update(sf::Event const& event, sf::Time const time) {

    for(auto o: objects)
    {
        o -> update(event, objects, time);
        for (auto obj : objects) {
            if (obj != o) {
                o->collision(obj);
            }
            if (auto ptr = dynamic_cast<Base *>(obj)) {

                if (!ptr->is_alive()) {
                    if (ptr->getTeam() == 1) {
                        scoreTwo += 1;
                    } else if (ptr->getTeam() == 2) {
                        scoreOne += 1;
                    }

                    roundOver = true;
                    break;
                }
            }
            if (auto ptr = dynamic_cast<Player *>(obj)) {
                if (!ptr->is_alive()) {

                    //Detta gör att spelaren spawnar tillbaka vid sin bas.
                    //I nuläget finns en bugg som sker när man dödar en motståndare
                    // medans man står i dess spawnpoint.
                    ptr->getSprite().setPosition(ptr->getSpawnpoint_x(), ptr->getSpawnpoint_y());
                    ptr->increase_hp();

                }
            }
            if (roundOver) {
                break;
            }
        }

    }

    removeFromBoard();
}

void PlayState::draw(sf::RenderTarget& window) const {
    for (auto o: objects)
    {
        window.draw(o->getSprite());
    }

}

void PlayState::removeFromBoard()
{
    std::vector<Object*> removedObjects{};
    objects.erase(std::remove_if(std::begin(objects), std::end(objects),
            [](Object* o)
            {
                if(auto ptr = dynamic_cast<Destroyable*>(o))
                {

                    if(!ptr->is_alive())
                    {
                        delete ptr;
                        ptr = nullptr;
                        return true;
                    }
                }
                return false;
            }),end(objects));
}

void PlayState::make_arena() {
    std::string line;
    double y{0};
    std::ifstream ifs{filepath};
    if(!ifs)
    {
        std::cerr << "Failed to load " << filepath << std::endl;
    }
    while(getline(ifs, line)) {
        double x{0};
        for (char c: line) {
            if (c == '#') {
                Undestroyable NonDesWall{x, y, sprites["NonDesWall"]};
                NonDesWall.getSprite().setPosition(x, y);
                objects.push_back(new Undestroyable{NonDesWall});
            } else if (c == 'H') {
                DesWall Des_Wall{x, y, sprites["DesWall"], 1};
                Des_Wall.getSprite().setPosition(x, y);
                objects.push_back(new DesWall{Des_Wall});
            } else if (c == 'B') {
                Base base{x, y, sprites["BaseOne"], 1, 1};
                base.getSprite().setPosition(x, y);
                objects.push_back(new Base{base});
            } else if (c == 'b') {
                Base baseTwo{x, y, sprites["BaseTwo"], 1, 2};
                baseTwo.getSprite().setPosition(x, y);
                objects.push_back(new Base{baseTwo});
            } else if (c == '1') {
                Player p1{x, y, sprites["Player"], 1, 1, sprites["Projectile"]};
                p1.getSprite().setPosition(x, y);
                objects.push_back(new Player{p1});

            } else if (c == '2') {
                Player p2{x, y, sprites["PlayerTwo"], 1, 2, sprites["Projectile"]};
                p2.getSprite().setPosition(x, y);
                objects.push_back(new Player{p2});
            }
            else if (c == '3') {
                Player p3{x, y, sprites["PlayerThree"], 1, 3, sprites["Projectile"]};
                p3.getSprite().setPosition(x, y);
                objects.push_back(new Player{p3});
            }
            else if (c == '4') {
                Player p4{x, y, sprites["PlayerFour"], 1, 4, sprites["Projectile"]};
                p4.getSprite().setPosition(x, y);
                objects.push_back(new Player{p4});
            }
            x += 50;
        }
        y += 50;
    }
}

void PlayState::create_sprites() {
    sf::Sprite player_sprite{};
    player_sprite.setTexture(*textures["Player"]);
    player_sprite.setOrigin(40/2, 40/2);

    sf::Sprite playerTwo_sprite{};
    playerTwo_sprite.setTexture(*textures["PlayerTwo"]);
    playerTwo_sprite.setOrigin(40/2, 40/2);

    sf::Sprite playerThree_sprite{};
    playerThree_sprite.setTexture(*textures["PlayerThree"]);
    playerThree_sprite.setOrigin(40/2, 40/2);

    sf::Sprite playerFour_sprite{};
    playerFour_sprite.setTexture(*textures["PlayerFour"]);
    playerFour_sprite.setOrigin(40/2, 40/2);

    sf::Sprite DesWall_sprite{};
    DesWall_sprite.setTexture(*textures["DesWall"]);
    DesWall_sprite.setOrigin(50/2, 50/2);

    sf::Sprite NonDesWall_sprite{};
    NonDesWall_sprite.setTexture(*textures["NonDesWall"]);
    NonDesWall_sprite.setOrigin(50/2, 50/2);

    sf::Sprite baseOne_sprite{};
    baseOne_sprite.setTexture(*textures["BaseOne"]);
    baseOne_sprite.setOrigin(50/2, 50/2);

    sf::Sprite baseTwo_sprite{};
    baseTwo_sprite.setTexture(*textures["BaseTwo"]);
    baseTwo_sprite.setOrigin(50/2, 50/2);

    sf::Sprite projectile_sprite{};
    projectile_sprite.setTexture(*textures["Projectile"]);
    projectile_sprite.setOrigin(25/2, 25/2);

    sprites.insert(std::pair<std::string, sf::Sprite>("Player", player_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("PlayerTwo", playerTwo_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("PlayerThree", playerThree_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("PlayerFour", playerFour_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("DesWall", DesWall_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("NonDesWall", NonDesWall_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("BaseOne", baseOne_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("BaseTwo", baseTwo_sprite));
    sprites.insert(std::pair<std::string, sf::Sprite>("Projectile", projectile_sprite));
}

void PlayState::create_textures() {
    sf::Texture player_t;
    if(!player_t.loadFromFile("images/player.png"))
    {
        std::cerr << "Failed to load images/player.png" << std::endl;
    }

    sf::Texture playerTwo_t;
    if(!playerTwo_t.loadFromFile("images/playerTwo.png"))
    {
        std::cerr << "Failed to load images/playerTwo.png" << std::endl;
    }

    sf::Texture playerThree_t;
    if(!playerThree_t.loadFromFile("images/playerThree.png"))
    {
        std::cerr << "Failed to load images/playerThree.png" << std::endl;
    }

    sf::Texture playerFour_t;
    if(!playerFour_t.loadFromFile("images/playerFour.png"))
    {
        std::cerr << "Failed to load images/playerFour.png" << std::endl;
    }

    sf::Texture DesWall_t;
    if(!DesWall_t.loadFromFile("images/DesWall.png"))
    {
        std::cerr << "Failed to load images/DesWall.png" << std::endl;
    }

    sf::Texture NonDesWall_t;
    if(!NonDesWall_t.loadFromFile("images/NonDesWall.png"))
    {
        std::cerr << "Failed to load images/NonDesWall.png" << std::endl;
    }

    sf::Texture BaseOne_t;
    if(!BaseOne_t.loadFromFile("images/base.png"))
    {
        std::cerr << "Failed to load images/base.png" << std::endl;
    }

    sf::Texture BaseTwo_t;
    if(!BaseTwo_t.loadFromFile("images/base2.png"))
    {
        std::cerr << "Failed to load images/base.png" << std::endl;
    }

    sf::Texture proj_t;
    if(!proj_t.loadFromFile("images/Projectile.png"))
    {
        std::cerr << "Failed to load images/Projectile.png" << std::endl;
    }

    textures.insert(std::pair<std::string, sf::Texture*>("Player", new sf::Texture{player_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("PlayerTwo", new sf::Texture{playerTwo_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("PlayerThree", new sf::Texture{playerThree_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("PlayerFour", new sf::Texture{playerFour_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("DesWall", new sf::Texture{DesWall_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("NonDesWall", new sf::Texture{NonDesWall_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("BaseOne", new sf::Texture{BaseOne_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("BaseTwo", new sf::Texture{BaseTwo_t}));
    textures.insert(std::pair<std::string, sf::Texture*>("Projectile", new sf::Texture{proj_t}));
}

void PlayState::emptyBoard() {
    for(auto p: objects)
    {
        delete p;
        p = nullptr;
    }

    objects.clear();
}

void PlayState::resetScore()
{
    scoreOne = 0;
    scoreTwo = 0;
}

void PlayState::setFilepath(std::string newPath) {

    filepath = newPath;
}

bool PlayState::hasWon() const {
    return scoreOne == 3 || scoreTwo == 3;
}

std::string PlayState::getWinner() const{
    if(scoreOne == 3)
    {
        return "Team one has won!";
    }

    if(scoreTwo == 3)
    {
        return "Team Two has won!";
    }
}

//Displaying the scoreboard of each team is handled in this function.
void PlayState::draw_scoreboard(sf::RenderWindow &window) const {
    sf::Font font;
    if(!font.loadFromFile("fonts/pixelfont.otf"))
    {
        std::cerr << "Failed to load fonts/pixelfont.otf" << std::endl;
    }
    sf::Text team1;
    team1.setFont(font);
    team1.setString("Team 1: "+ std::to_string(scoreOne));
    team1.setPosition(window.getSize().x-350, 100);
    window.draw(team1);

    sf::Text team2;
    team2.setFont(font);
    team2.setString("Team 2: "+ std::to_string(scoreTwo));
    team2.setPosition(window.getSize().x-350, 300);
    window.draw(team2);
}

//Checks if one of the bases have been destroyed. And resets the map.
void PlayState::isRoundOver() {
    if (roundOver) {
        emptyBoard();
        make_arena();
        roundOver = false;
    }
};

