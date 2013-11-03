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

        ~Context() noexcept;

        zmq::socket_t&
        get_subscriber() const noexcept;

        const Plugins&
        get_plugins() const noexcept;

        void
        send(std::string s);

        std::string
        receive();

    private:
        zmq::context_t _zmq_context;
        mutable zmq::socket_t _subscriber;
        const Plugins _plugins;
    };
}

#endif