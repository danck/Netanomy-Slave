#ifndef __CONTEXT__
#define __CONTEXT__

#include <zmq.hpp>
#include "plugins.hpp"

/**
@brief Provides context operations and data for the states
*/
namespace nty
{
  class Context 
  {
  public:
    Context();
    
    ~Context();
    
    zmq::socket_t&
    get_listen_socket() const noexcept;
    
    const Plugins&
    get_plugins() const noexcept;

  private:
    zmq::context_t _zmq_context;
    mutable zmq::socket_t _listen_socket;
    const Plugins _plugins;
  };
}

#endif
