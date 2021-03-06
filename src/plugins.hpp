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

#ifndef __PLUGINS__
#define __PLUGINS__

#include <string>
#include <memory>
#include <map>
#include "plugin.hpp"

namespace nty
{
  
  class Plugins
  {
  public:
    Plugins(const std::string &plugin_dir);
    
    ~Plugins() noexcept;
    
    const std::unique_ptr<Plugin>&
    lookup(const Plugin::plugin_id_type id) const;
    
  private:
    typedef std::map<Plugin::plugin_id_type, std::unique_ptr<Plugin> > _id2plugin_type;
    _id2plugin_type _id2plugin;
  };

}

#endif
