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

#ifndef __EXEC_REPLY_STATE__
#define __EXEC_REPLY_STATE__

#include "state.hpp"
#include "plugin.hpp"

namespace nty
{
    class Request;

    /**
    @brief Executes plugin, waits for results and submits them to the master.
    */
    class ExecReplyState : public State
    {
    public:
        ExecReplyState(const std::shared_ptr<Context> &context,
        	   std::unique_ptr<Request> &&request) noexcept;

        ~ExecReplyState() noexcept;

	/**
	@brief Runs the ExecReplyState.
	*/
        std::unique_ptr<State>
        run();

	/**
	@brief Sends result to master. 
	*/
        void send_result(const RequestExecutor::reply_type result);

    private:
        std::unique_ptr<Request> _request;
    };
}

#endif
