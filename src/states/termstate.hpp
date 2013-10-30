#ifndef __TERM_STATE__
#define __TERM_STATE__

// manages a clean shutdown of context and initializes termination of the state machine

namespace nty
{
	class TermState
	{
	public:
		TermState(nty::Context c);
		~TermState();
	};
}

#endif