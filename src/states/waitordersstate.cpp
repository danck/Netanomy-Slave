#include "waitordersstate.hpp"
#include "execreplystate.hpp"
#include <context.hpp>
#include <request.hpp>
#include <zmq.hpp>
#include <string.h>

using namespace nty;
 
WaitOrdersState::WaitOrdersState(const std::shared_ptr<Context> &context) noexcept
: State(context)
{}

WaitOrdersState::~WaitOrdersState() noexcept
{}

std::unique_ptr<State>
WaitOrdersState::run()
{
  zmq::message_t msg;
  this->get_context()->get_listen_socket().recv(&msg, 0);
  
  Plugin::plugin_id_type plugin_id;
  memcpy(&plugin_id, msg.data(), sizeof(Plugin::plugin_id_type));
  
  std::vector<char> request_data(static_cast<char*>(msg.data()) + sizeof(Plugin::plugin_id_type),
				 static_cast<char*>(msg.data()) + msg.size());
  
  std::unique_ptr<Request> request(new Request(plugin_id, std::move(request_data)));
  return std::unique_ptr<State>(new ExecReplyState(this->get_context(), std::move(request)));
}
