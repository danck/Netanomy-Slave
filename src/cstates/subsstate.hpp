#ifndef __SUBS_STATE__
#define __SUBS_STATE__

// This state obtains local system information and uses it to
// choose the correct subsciption channel and performs subsription

namespace nty
{
	
	class SubsState
	{
	public:

		SubsState(nty::Context c);
		~SubsState();
	};
}

#endif