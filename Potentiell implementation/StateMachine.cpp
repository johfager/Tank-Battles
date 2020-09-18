//
// Created by johfa464 on 2019-12-11.
//

#include "StateMachine.h"
#include "State.h"

#include <iostream>
#include <memory>


StateMachine::StateMachine()
: m_resume{false}, m_running{false}

void StateMachine::run(std::unique_ptr<State> state) {

    m_running = true;
    m_states.push(std::move(state));
}

void StateMachine::nextState() {
if(m_resume)
    {
    //Städar nuvarande state.
    if (!m_states.empty())
        {
        m_states.pop()
        }
    //Återupptar förra state.
    if(!m_states.empty())
        {
        m_states.top()->resume();
        }
    m_resume = false;
    }

    //Då vi måste ha en state så gör vi följande
    if (!m_states.empty())
    {
        std::unique_ptr<State> temp = m_states.top()->next();


        //Vi vill bara byta stae när det finns i next
        if(temp != nullptr)
        {
            //Byt ut nuvarande state.
            if(temp->isReplacing())
            {
                m_states.pop();
            }
            //Eller pausa nuvarande state
            else
                {
                m_states.top()->pause();
                }
            m_states.push(std::move(temp));
        }
    }

}

void StateMachine::lastState() {

    m_resume = true;
}

void StateMachine::update() {
    //Låter state uppdatera programmet
    m_states.top()->update();
}

void StateMachine::draw() {
    //Låter state köra draw
    m_states.top()->draw();
}

