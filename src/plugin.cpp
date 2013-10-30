#include "plugin.hpp"

using namespace nty;

RequestExecutor::~RequestExecutor() noexcept
{}

Plugin::Plugin(const plugin_id_type id)
  : _id(id)
{}

Plugin::~Plugin() noexcept
{}

Plugin::plugin_id_type
Plugin::get_plugin_id()
{
  return _id;
}
