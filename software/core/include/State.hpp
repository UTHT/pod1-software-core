#ifndef STATE_HPP
#define STATE_HPP

// This is just temporary until we have a STATES enum.
enum STATES {};

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
