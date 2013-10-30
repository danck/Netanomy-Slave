#include "null_plugin.hpp"
#include "plugin.hpp"

using namespace nty;

class NullPlugin : public Plugin
{
public:
  NullPlugin();
  
  virtual ~NullPlugin() noexcept;
  
  virtual
  std::unique_ptr<RequestExecutor>
  instantiate_executor(const std::shared_ptr<Context> &context,
		      const std::unique_ptr<Request> &request);
  
private:
  static const plugin_id_type _null_plugin_id = 0;
};

class NullExecutor : public RequestExecutor
{
public:
  ~NullExecutor() noexcept;

  std::vector<char>
  run(const std::shared_ptr<Context> &context,
      const std::unique_ptr<Request> &request);
};

NullPlugin::NullPlugin()
  : Plugin(_null_plugin_id)
{}

NullPlugin::~NullPlugin() noexcept
{}

std::unique_ptr<RequestExecutor>
NullPlugin::instantiate_executor(const std::shared_ptr<Context> &context,
				 const std::unique_ptr<Request> &request)
{
  return std::unique_ptr<NullExecutor>(new NullExecutor());
}


NullExecutor::~NullExecutor() noexcept
{}


RequestExecutor::reply_type
NullExecutor::run(const std::shared_ptr<Context> &context,
		  const std::unique_ptr<Request> &request)
{
  return reply_type();
}

std::unique_ptr<Plugin>
nty::null_plugin_load()
{
  return std::unique_ptr<Plugin>(new NullPlugin());
}
