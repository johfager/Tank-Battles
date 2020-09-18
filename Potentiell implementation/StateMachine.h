//
// Created by johfa464 on 2019-12-11.
//

#ifndef TANKDUELS_STATEMACHINE_H
#define TANKDUELS_STATEMACHINE_H
#include <memory>
#include <stack>
#include <string>
class State;
namespace sf
{
    class RenderWindow;
}
class StateMachine {
public:

    StateMachine();

    void run(std::unique_ptr<State> state);

    void nextState();
    void lastState();

    void update();
    void draw();

    bool running()
    {
        return m_running;
    }
    void quit(){
        m_running = false;
    }
    template <typename T>
    static std:: unique_ptr<T> build(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

private:
    //Våran variabel som håller koller på states. vi använder oss av en stack med pekare.
    std::stack<std::unique_ptr<State>> m_states;
    bool m_resume;
    bool m_running;
};

//Här bygger vi våran stack pekare som tar in vilket state det är, window samt vilket en bool som hjälper oss
//att se om den ska bytas ut.
template <typename T>
std::unique_ptr<T> StateMachine::build(StateMachine& machine, sf::RenderWindow& window, bool replace)
{
    return std::unique_ptr<T>( new T(machine, window, replace));
}


#endif //TANKDUELS_STATEMACHINE_H
