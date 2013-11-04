#ifndef __NTY_REQUEST__
#define __NTY_REQUEST__

#include <string>
#include "plugin.hpp"

namespace nty
{
    /*
    @brief  A package addressing a particular plugin and containing the data to deliver
    */
    class Request
    {
    public:
        typedef std::string request_data_type;

        Request(const Plugin::plugin_id_type plugin_id,
            request_data_type &&request_data);

        const Plugin::plugin_id_type
        get_plugin_id() const noexcept;

        const request_data_type&
        get_request_data() const noexcept;

    private:
        Plugin::plugin_id_type _plugin_id;
        request_data_type _request_data;
    };
}

#endif