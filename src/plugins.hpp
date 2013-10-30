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
