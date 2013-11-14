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

#ifndef __NTY_REQUEST__
#define __NTY_REQUEST__

#include <string>
#include "plugin.hpp"

namespace nty
{
    /*
    @brief  A package addressing a particular plugin and containing the data to deliver
    */
    class Request
    {
    public:
        typedef std::string request_data_type;

        Request(const Plugin::plugin_id_type plugin_id,
            request_data_type &&request_data);

        const Plugin::plugin_id_type
        get_plugin_id() const noexcept;

        const request_data_type&
        get_request_data() const noexcept;

    private:
        Plugin::plugin_id_type _plugin_id;
        request_data_type _request_data;
    };
}

#endif