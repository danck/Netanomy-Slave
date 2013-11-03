#ifndef __WAIT_ORDERS_STATE__
#define __WAIT_ORDERS_STATE__

#include "state.hpp"

// In this state the slave awaits orders from the server on the given
// channel, i.e.: which test to execute

namespace nty
{
  class WaitOrdersState : public State
  {
	public:
		WaitOrdersState(const std::shared_ptr<Context> &context) noexcept;

		virtual ~WaitOrdersState() noexcept;

		virtual std::unique_ptr<State>
		run();
	};
}

#endif
