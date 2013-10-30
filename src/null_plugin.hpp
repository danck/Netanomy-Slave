#ifndef __NULL_PLUGIN__
#define __NULL_PLUGIN__

#include <memory>

namespace nty
{
  class Plugin;
  
  std::unique_ptr<Plugin>
  null_plugin_load();
}

#endif
