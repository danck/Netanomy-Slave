#ifndef __WAIT_ORDERS_STATE__
#define __WAIT_ORDERS_STATE__

// In this state the slave awaits orders from the server on the given
// channel, i.e.: which test to execute

namespace nty
{
	class WaitOrdersState
	{
	public:
		WaitOrdersState(nty::Context c);
		~WaitOrdersState();
	};
}

#endif