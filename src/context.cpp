#include "context.hpp"
#include <zmq.hpp>
#include <string>

using namespace nty;

Context::Context()
    : _zmq_context(1), _subscriber(_zmq_context, ZMQ_SUB), _plugins(NTY_PLUGINS_DIR)
{
    // Set filter according to this particular host
    std::string filter = "Linux";
    _subscriber.setsockopt(ZMQ_SUBSCRIBE, filter.data(), strlen(filter.data()));

    _subscriber.connect("tcp://localhost:11000");
}

Context::~Context() noexcept
{}

zmq::socket_t&
Context::get_subscriber() const noexcept
{
    return _subscriber;
}

const Plugins&
Context::get_plugins() const noexcept
{
    return _plugins;
}

zmq::context_t&
Context::get_zmq_context() noexcept
{
    return _zmq_context;
}