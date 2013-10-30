#include "statehandler.hpp"
#include <states/waitordersstate.hpp>

using namespace nty;

StateHandler::StateHandler(const std::shared_ptr<Context> &context)
  : _state(new WaitOrdersState(context))
{}

StateHandler::~StateHandler() noexcept
{}

void
StateHandler::run()
{
  while(_state.get() != nullptr)
    _state = _state->run();
}
