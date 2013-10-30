#ifndef __REQUEST__
#define __REQUEST__

#include <vector>
#include "plugin.hpp"

namespace nty
{
  class Request
  {
  public:
    typedef std::vector<char> request_data_type;
    
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
