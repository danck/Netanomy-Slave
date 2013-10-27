#ifndef __PREP_STATE
#define __PREP_STATE

// This state checks for the received tasks:
// Is the plugin already installed or does it need to be pulled and installed first?

namespace nty
{
	class PrepState
	{
	public:
		PrepState(nty::Context c);
		~PrepState();
	};
}

#endif