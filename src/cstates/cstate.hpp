#ifndef __CSTATE__
#define __CSTATE__

#include "state_t.hpp"

// Interface class for slave states

class Cstate {
	public:

		/**
		@brief	terminates current state object and returns a successor type
		@params	
		@return
		*/
		state_t switch_state (state_t s) = 0;
};

#endif