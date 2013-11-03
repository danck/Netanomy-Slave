#include "plugins.hpp"
#include "plugin.hpp"

#include "null_plugin.hpp"

using namespace nty;

Plugins::Plugins(const std::string &plugin_dir)
{
	std::unique_ptr<Plugin> null_plugin(null_plugin_load());
	const Plugin::plugin_id_type null_plugin_id = null_plugin->get_plugin_id();
	_id2plugin.insert(_id2plugin_type::value_type(null_plugin_id, std::move(null_plugin)));
}

Plugins::~Plugins() noexcept
{}

const std::unique_ptr<Plugin>&
Plugins::lookup(const Plugin::plugin_id_type id) const
{
	return _id2plugin.at(id);
}
