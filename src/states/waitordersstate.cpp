#include <context.hpp>
#include <request.hpp>
#include <zmq.hpp>
#include <string>
#include <iostream>
#include <cassert>
#include "waitordersstate.hpp"
#include "execreplystate.hpp"
#include "zhelpers.hpp"
#include "plugins.hpp"

using namespace nty;
 
WaitOrdersState::WaitOrdersState(const std::shared_ptr<Context> &context) noexcept
    : State(context)
{}

WaitOrdersState::~WaitOrdersState() noexcept
{}

std::unique_ptr<State>
WaitOrdersState::run()
{
    std::cout << "## Switched to WaitOrdersState ##" << std::endl << std::endl;

    zmq::socket_t& subscriber = get_context()->get_subscriber();
    
    while (true)
    {        
        // Consume envelope with address
        std::string address     = zhelpers::s_recv (subscriber);
        // assert(address.compare(get_context()->filter))

        // Receive and store message contents
        std::string contents    = zhelpers::s_recv (subscriber);

        // dissamble message
        unsigned first_delim            = contents.find(" ");
        Plugin::plugin_id_type pl_id    = std::stoi(contents.substr(0, first_delim));
        Request::request_data_type data = contents.substr(first_delim + 1);

        // this should be replaced by a proper logger
        std::cout << "Received:" << std::endl 
            << "Address: " << " [" << address << "] " << std::endl
            << "Plugin ID: " << " [" << std::to_string(pl_id) << "] " << std::endl
            << "Data: " << " [" << data  << "] " <<  std::endl << std::endl;

        // check for plugin_id????

        // Assemble 'Request' from received content
        std::unique_ptr<Request> request(
            new Request(pl_id, std::move(data)));

        // Construct and return next state
        return std::unique_ptr<State>(
            new ExecReplyState(this->get_context(), std::move(request)));
    }

}


    // zmq::message_t msg;
    // this->get_context()->get_socket().recv(&msg);

    // // Plugin::plugin_id_type plugin_id;
    // // memcpy(&plugin_id, msg.data(), sizeof(Plugin::plugin_id_type));

    // std::cout << "\n##Order received##\n";
    // std::cout << "size: " << msg.size() << std::endl;
    // char* my_msg = (char*) malloc(msg.size()+1);
    // memcpy(my_msg, msg.data(), 4);
    // my_msg[4] = '\0';
    // std::cout << "message: " << my_msg << std::endl;
    // free(my_msg);

    // // std::vector<char> request_data(static_cast<char*>(msg.data()) + sizeof(Plugin::plugin_id_type),
    //  //       static_cast<char*>(msg.data()) + msg.size());

    // // std::unique_ptr<Request> request(new Request(plugin_id, std::move(request_data)));

    // std::cin.ignore();

    // return std::unique_ptr<State>(new ExecReplyState(this->get_context(), std::move(request)));