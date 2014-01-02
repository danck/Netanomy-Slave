/* ========================================================
Homework for SE2 practical course, HAW Hamburg

Copyright (c) 2013, Yavuz Arslan, Daniel Kirchner
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
============================================================ */

// Yavuz Arslan <yavuz.arslan@haw-hamburg.de>
// Daniel Kirchner <daniel.kirchner1@haw-hamburg.de>

#ifndef __STATE_HANDLER__
#define __STATE_HANDLER__

#include <memory>

namespace nty
{
    class Context;
    class State;
      
    /**
    @brief  Manages execution cycle of state routines
    */
    class StateHandler 
    {
    public:

        StateHandler(const std::shared_ptr<Context> &context);

        ~StateHandler() noexcept;

        /**
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