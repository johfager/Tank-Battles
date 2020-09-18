//
// Created by johfa464 on 2019-12-11.
//


#include "StateMachine.h"
#include "MenuState.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <iostream>

MenuState::MenuState(StateMachine &machine, sf::RenderWindow &window,
        bool replace)
        :State{machine, window, replace}
        {
            m_bgTex.loadFromFile("images/start_menu.png");
            m_bg.setTexture(m_bgTex);


}

void MenuState::pause() {
    std::cout << "MenuState Pause" << std::endl;
}

void MenuState::resume() {
    std::cout << "MenuState Resume" << std::endl;
}

void MenuState::update() {
    sf::Event event;

    while( m_window.pollEvent( event ) )
    {
        switch( event.type )
        {
            case sf::Event::Closed:
                m_machine.quit();
                break;

            case sf::Event::KeyPressed:
                switch( event.key.code )
                {
                    case sf::Keyboard::Escape:
                        m_machine.lastState();
                        break;

                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }

void MenuState::draw() {

        //Rensar den föregående utskriften
    m_window.clear();
    m_window.draw( m_bg );
    m_window.display();
}
