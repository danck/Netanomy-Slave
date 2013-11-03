#include "execreplystate.hpp"
#include "waitordersstate.hpp"
#include <context.hpp>
#include <request.hpp>
#include <iostream>

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
	std::cout << "exec reply state" << std::endl;
	this->get_context()->get_plugins().lookup(_request->get_plugin_id())
    ->instantiate_executor(this->get_context(), _request)->run
    (this->get_context(), _request);

	return std::unique_ptr<State>(new WaitOrdersState(this->get_context()));
}