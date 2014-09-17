#ifndef __REGISTRY__HPP__
#define __REGISTRY__HPP__

#include <memory>

namespace plugin { class Manager; }

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

#endif
