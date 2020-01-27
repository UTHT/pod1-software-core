#include "State.hpp"

State::State(States name) : name(name){
}

State::~State(){
}

States State::get_name(){
    return this->name;
}
