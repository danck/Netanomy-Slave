#ifndef __INIT_STATE_T__
#define __INIT_STATE_T__

// Initialisation state
// Obtains system information to choose correct channel subscription

#include "cstate.hpp"

namespace nty
{

	class InitState: public nty::State 
	{

	public:
		nty::Context c;

		InitState(nty::Context c);
		~InitState();
	};
}

#endif