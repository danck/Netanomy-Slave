#ifndef __EXEC_REPLY_STATE__
#define __EXEC_REPLY_STATE__

#include "state.hpp"

// Executes plugin, waits for results and submits them to the master
namespace nty
{
  class Request;
  
  class ExecReplyState : public State
  {
  public:
    ExecReplyState(const std::shared_ptr<Context> &context,
		   std::unique_ptr<Request> &&request) noexcept;
    
    virtual ~ExecReplyState() noexcept;
    
    virtual std::unique_ptr<State>
    run();
    
  private:
    std::unique_ptr<Request> _request;
  };
}

#endif
