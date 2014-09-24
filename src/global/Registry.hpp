#ifndef __GLOBAL__REGISTRY__HPP__
#define __GLOBAL__REGISTRY__HPP__

#include <memory>

namespace plugin
{
class Manager;
}

namespace global
{

class Registry
{
public:
	static Registry& get();

	void inject(std::shared_ptr<::plugin::Manager> manager);
	std::shared_ptr<::plugin::Manager> plugins() const;

private:
	Registry();
	~Registry();

	static Registry* instance;

	std::shared_ptr<::plugin::Manager> plugin_manager;
};

}

#endif
