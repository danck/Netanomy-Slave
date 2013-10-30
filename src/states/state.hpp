#ifndef __STATE__
#define __STATE__

#include <memory>

namespace nty
{
  // forward declaration
  class Context;
  
  class State 
  {
  public:
    State(const std::shared_ptr<Context> &context) noexcept;
    
    virtual ~State() noexcept = 0;
    
    virtual std::unique_ptr<State>
    run() = 0;
    
  protected:
    const std::shared_ptr<Context>&
    get_context() const noexcept;

  private:
    std::shared_ptr<Context> _context;
  };
}

#endif
