#ifndef STATE_HPP
#define STATE_HPP

#include "state_enum.hpp"

class State {
    private:
        /* This makes it easer to log, debug, and validate transitions later on.
         * */
        STATES name;
    public:
        State(STATES name);
        ~State();

        /* Perform logic related to the current state and return when a state transition is desired. */
        virtual State& run() = 0;

        STATES getName();
};

#endif /* STATE_HPP */
