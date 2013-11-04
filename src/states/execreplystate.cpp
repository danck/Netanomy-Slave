#include "execreplystate.hpp"
#include "waitordersstate.hpp"
#include "plugin.hpp"
#include "zhelpers.hpp"
#include "zmq.hpp"
#include <context.hpp>
#include <request.hpp>
#include <iostream>
#include <memory>

using namespace nty;

ExecReplyState::ExecReplyState(const std::shared_ptr<Context> &context,
			       std::unique_ptr<Request> &&request) noexcept
: State(context), _request(std::move(request))
{}

ExecReplyState::~ExecReplyState() noexcept
{}  

std::unique_ptr<State>
ExecReplyState::run()
{
	std::cout << "## Switched to ExecReplyState ##" << std::endl << std::endl;

	// Lookup plugin, pass request, execute
	RequestExecutor::reply_type reply = this->get_context()->get_plugins().lookup(_request->get_plugin_id())
    ->instantiate_executor(this->get_context(), _request)->run
    (this->get_context(), _request);

    this->send_result(reply);

	return std::unique_ptr<State>(new WaitOrdersState(this->get_context()));
}

void
ExecReplyState::send_result(const RequestExecutor::reply_type result)
{
	// Prepare context and socket
    zmq::socket_t returner (this->get_context()->get_zmq_context(), ZMQ_REQ);

	std::cout << "Returning result: " << "[" << result << "]" << std::endl << std::endl;
    returner.connect ("tcp://localhost:11001");
    zhelpers::s_send (returner, result);
    std::string rep = zhelpers::s_recv (returner);
    if (rep.compare("ACK"))
		std::cout << "Message confirmed." << std::endl << std::endl;
    returner.close();
}