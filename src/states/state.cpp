#include "state.hpp"

using namespace nty;

State::State(const std::shared_ptr<Context> &context) noexcept
: _context(context)
{}

State::~State() noexcept
{}

const std::shared_ptr<Context>&
State::get_context() const noexcept
{
  return _context;
}
