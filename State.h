//
// Created by johfa464 on 2019-12-09.
//

#ifndef TANKDUELS_STATE_H
#define TANKDUELS_STATE_H


//Class that represents "States" which means the different states the game can be in. An example of this is
// the "PlayState" which is when the game is being played.
//class State: public std::enable_shared_from_this<State>{
/**
 * Class representing a State.
 */
class State{
public:
    State();
    virtual ~State ()= default;

};


#endif //TANKDUELS_STATE_H
