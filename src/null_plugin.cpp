#include <iostream>
#include <thread>
#include <unistd.h>
#include "null_plugin.hpp"
#include "plugin.hpp"
#include "request.hpp"

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
    // NullExecutor();
    ~NullExecutor() noexcept;

    RequestExecutor::reply_type
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

/*
@brief  Echoes received data
*/
RequestExecutor::reply_type
NullExecutor::run(const std::shared_ptr<Context> &context,
	const std::unique_ptr<Request> &request)
{
    std::cout << "Yes, this is NullPlugin." << std::endl;
    sleep(2);
    RequestExecutor::reply_type rp = request->get_request_data();
    return rp;
}

std::unique_ptr<Plugin>
nty::null_plugin_load()
{
    return std::unique_ptr<Plugin>(new NullPlugin());
}