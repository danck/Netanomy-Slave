#include "waitordersstate.hpp"
#include "execreplystate.hpp"
#include <context.hpp>
#include <request.hpp>
#include <zmq.hpp>
#include <string.h>
#include <iostream>
#include "zhelpers.hpp"

using namespace nty;
 
WaitOrdersState::WaitOrdersState(const std::shared_ptr<Context> &context) noexcept
    : State(context)
{}

WaitOrdersState::~WaitOrdersState() noexcept
{}

std::unique_ptr<State>
WaitOrdersState::run()
{
    while (true)
    {

        zmq::socket_t& subscriber = get_context()->get_subscriber();
        
        // Read envelope with address
        std::string address = zhelpers::s_recv (subscriber);
            
        // Read message contents
        std::string contents = zhelpers::s_recv (subscriber);

        std::cout << "[" << address << "] " << contents << std::endl;
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
    // 	// 		 static_cast<char*>(msg.data()) + msg.size());

    // // std::unique_ptr<Request> request(new Request(plugin_id, std::move(request_data)));

    // std::cin.ignore();

    // return std::unique_ptr<State>(new ExecReplyState(this->get_context(), std::move(request)));
    return NULL;
}
