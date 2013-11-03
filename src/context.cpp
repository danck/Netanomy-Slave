#include "context.hpp"
#include <zmq.hpp>
#include <string>
#include <iostream>

using namespace nty;

Context::Context()
    : _zmq_context(1), _subscriber(_zmq_context, ZMQ_SUB), _plugins(NTY_PLUGINS_DIR)
{
    _subscriber.connect("tcp://localhost:11000");
    _subscriber.setsockopt( ZMQ_SUBSCRIBE, "Linux1", 1);

    std::cout << "in context" << std::endl;


    // // Connect and request ID
    // std::cout << "Connected to tcp://localhost:11000" << std::endl;
    // zmq::message_t request (5);
    // memcpy ((void *) request.data (), "Huhu", 4);
    // std::cout << "Requesting UID " << std::endl;
    // _socket.send(request);

    // // Get reply (hopfully a proper UID)
    // zmq::message_t reply;
    // _socket.recv(&reply);
    // std::cout << "Received something" << std::endl;

    // // Confirm if happy
    // zmq::message_t happy (6);
    // memcpy ((void *) happy.data (), "Happy", 5);
    // _socket.send(happy);
    // std::cout << "Stated my happiness" << std::endl;
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