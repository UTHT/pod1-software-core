#include "State.hpp"

State::State(){
}
State::State(STATES name) : name(name){
}

State::~State(){
}

STATES State::get_name(){
    return this->name;
}
