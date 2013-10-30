#ifndef __STATE_HANDLER__
#define __STATE_HANDLER__

#include <memory>

/**
@brief handles state switches and context operations
*/
namespace nty
{
  class Context;
  class State;
  
  class StateHandler 
  {
  public:
    StateHandler(const std::shared_ptr<Context> &context);
    
    ~StateHandler() noexcept;
    
    void
    run();
    
  private:
    std::unique_ptr<State> _state;
  };
}

#endif
