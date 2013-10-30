#include "context.hpp"

using namespace nty;

Context::Context()
  : _zmq_context(1), _listen_socket(_zmq_context, ZMQ_REP), _plugins(NTY_PLUGINS_DIR)
{
  _listen_socket.bind("tcp://*:11001");
}

Context::~Context()
{}

zmq::socket_t&
Context::get_listen_socket() const noexcept
{
  return _listen_socket;
}

const Plugins&
Context::get_plugins() const noexcept
{
  return _plugins;
}
