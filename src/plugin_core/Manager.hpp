#ifndef __PLUGIN__MANAGER__HPP__
#define __PLUGIN__MANAGER__HPP__

#include <vector>

class QString;

namespace plugin {

class Plugin;
class Renderer;

class Manager
{
public:
	virtual ~Manager() {}

	virtual void load(const QString& plugin_path) = 0;
	virtual void unload() = 0;

	virtual void register_renderer(const Plugin*, const Renderer*) = 0;
	virtual std::vector<const Renderer*> get_renderers() const = 0;
};

}

#endif
