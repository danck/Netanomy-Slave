// Slave's main function
// start and end point of execution
#include "context.hpp"
#include "statehandler.hpp"
#include <memory>
#include <iostream>

using namespace nty;

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