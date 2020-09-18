//
// Created by johfa464 on 2019-12-11.
//

#ifndef TANKDUELS_MENUSTATE_H
#define TANKDUELS_MENUSTATE_H
#include "State.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

namespace sf
{
    class RenderWindow;
}

class MenuState : public State
{
public:
    MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

    void pause();
    void resume();

    void update();
    void draw();

private:
    sf::Texture m_bgTex;
    sf::Sprite m_bg;
};


#endif //TANKDUELS_MENUSTATE_H
