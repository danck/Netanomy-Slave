#ifndef __STATE_HANDLER__
#define __STATE_HANDLER__

#include <memory>

namespace nty
{
    class Context;
    class State;
      
    /*
    @brief  Manages execution cycle of state routines
    */
    class StateHandler 
    {
    public:

        /*
        @brief  Create the stat handler object.
        */
        StateHandler(const std::shared_ptr<Context> &context);

        /*
        @brief  Destroy the stat handler object.
        */
        ~StateHandler() noexcept;

        /*
        @brief  Maintain execution of state routines, starting with WaitOrdersState
        Runs the initial state (WaitOrdersState) and provide it with the the given context. 
        This method then takes the return value as the next state to run and
        thus maintains an execution cycle of state routines until a termination value
        is returned
        */
        void
        run();
    
    private:
        std::unique_ptr<State> _state;
    };
}

#endif