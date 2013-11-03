#include "statehandler.hpp"
#include <states/waitordersstate.hpp>
#include <iostream>

using namespace nty;

StateHandler::StateHandler(const std::shared_ptr<Context> &context)
	: _state(new WaitOrdersState(context))
{}

StateHandler::~StateHandler() noexcept
{}

void
StateHandler::run()
{
	std::cout << "in statehandler" << std::endl;

	// To break the state execution cycle return nullptr
  	while(_state.get() != nullptr)
   		_state = _state->run();	
}