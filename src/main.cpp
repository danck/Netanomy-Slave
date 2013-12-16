/** @mainpage Netanomy: Slave Component
*   @author Daniel Kirchner <daniel.kirchner1@haw-hamburg.de>
*   @author Yavuz Arslan <yavuz.arslan@haw-hamburg.de>
*   @version 0.0.1
*   @par Description:
*   - Runs on remote hosts
*   - Execute test plugin
*/

#include "context.hpp"
#include "statehandler.hpp"
#include <memory>
#include <iostream>

using namespace nty;

/**
   Starts the slave.
 */
int main (int argc, char ** argv) 
{
	// initialize state machine
	// start execution by entering init_state
	// clean exit

	// Create context
	std::cout << "in main" << std::endl;
	const std::shared_ptr<Context> context(new Context());

	StateHandler statehandler(context);
	statehandler.run();
	return 0;
}