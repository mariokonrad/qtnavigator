#include "Registry.hpp"

namespace global
{

Registry* Registry::instance = nullptr;

Registry::Registry() {}

Registry::~Registry() {}

Registry& Registry::get()
{
	if (!instance) {
		instance = new Registry;
	}
	return *instance;
}

void Registry::inject(std::shared_ptr<::plugin::Manager> manager)
{
	plugin_manager = manager;
}

std::shared_ptr<::plugin::Manager> Registry::plugins() const
{
	return plugin_manager;
}

}

