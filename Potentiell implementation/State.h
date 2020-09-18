//
// Created by johfa464 on 2019-12-09.
//

#ifndef TANKDUELS_STATE_H
#define TANKDUELS_STATE_H

#include <memory>

class StateMachine;

namespace sf
{
    class RenderWindow;
}

//class State: public std::enable_shared_from_this<State>{
class State{
public:
    State( StateMachine& machine, sf::RenderWindow& window,
            bool replace = true);
    virtual ~State ()= default;

    virtual void pause() = 0;
    virtual void resume() = 0;

    virtual void update() = 0;
    virtual void draw() = 0;

    std::unique_ptr<State> next();

    bool isReplacing();
    //virtual std::shared_ptr<State> tick(sf::Time time) = 0;
protected:
    StateMachine& m_machine;
    sf::RenderWindow& m_window;
    bool m_replacing;
    std::unique_ptr<State> m_next;
};


#endif //TANKDUELS_STATE_H
