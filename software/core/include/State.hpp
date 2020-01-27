#ifndef STATE_HPP
#define STATE_HPP

#include "helper/enums.hpp"

class State {
    private:
        /* This makes it easer to log, debug, and validate transitions later on.
         * */
        States name;
    public:
        State(States name);
        virtual ~State();

        /* Perform logic related to the current state and return when a state transition is desired. */
        virtual States run();

        States get_name();
};

#endif /* STATE_HPP */
