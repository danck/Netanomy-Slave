#ifndef __NTY_PLUGIN__
#define __NTY_PLUGIN__

#include <memory>
#include <vector>

namespace nty
{
    class ExecReplyState;
    class Context;
    class Request;

    class RequestExecutor
    {
    public:
    virtual ~RequestExecutor() noexcept = 0;

    typedef std::vector<char> reply_type;

    virtual reply_type
    run(const std::shared_ptr<Context> &context,
        const std::unique_ptr<Request> &request) = 0;
    };

    class Plugin
    {
    public:
        typedef int plugin_id_type;

        Plugin(const plugin_id_type id);

        virtual ~Plugin() noexcept = 0;

        virtual
        std::unique_ptr<RequestExecutor>
        instantiate_executor(const std::shared_ptr<Context> &context,
        		const std::unique_ptr<Request> &request) = 0;

        plugin_id_type
        get_plugin_id();

    private:
        plugin_id_type _id;
    };
}

#endif