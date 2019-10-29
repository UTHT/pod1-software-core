#include "../include/State.hpp"

State::State(STATES name) : name(name) {};

State::~State(){}

STATES State::getName(){
    return this->name;
}