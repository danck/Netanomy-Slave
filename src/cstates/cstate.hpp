#ifndef __STATE__
#define __STATE__

#include "state_t.hpp"

// Interface class for slave states

namespace nty
{

	class State 
	{
		public:

			/**
			@brief	terminates current state object and returns a successor state
			@params	
			@return
			*/
			virtual state_t switch_state (state_t s) = 0;
	};

}

#endif