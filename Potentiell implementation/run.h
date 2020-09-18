//
// Created by johfa464 on 2019-12-11.
//

#ifndef TANKDUELS_RUN_H
#define TANKDUELS_RUN_H
#include "StateMachine.hpp"
#include "StateMachine.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Run {
public:
    Run() = default;
    void run();

private:
    StateMachine m_machine;
    sf::RenderWindow m_window;
};




#endif //TANKDUELS_RUN_H
