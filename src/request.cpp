#include "request.hpp"

using namespace nty;

Request::Request(const Plugin::plugin_id_type plugin_id,
		 request_data_type &&request_data)
  : _plugin_id(plugin_id), _request_data(std::move(request_data))
{}
    
const Request::request_data_type&
Request::get_request_data() const noexcept
{
  return _request_data;
}

const Plugin::plugin_id_type
Request::get_plugin_id() const noexcept
{
  return _plugin_id;
}
