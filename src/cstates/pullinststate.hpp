#ifndef __PULL_INSTALL_STATE__
#define __PULL_INSTALL_STATE__

// In case the plugin isn't installed already, 
// this state pulls it from the master and installs it

namespace nty
{

	class PullInstState
	{
	public:

		PullInstState(nty::Context c);
		~PullInstState();
	};
}

#endif