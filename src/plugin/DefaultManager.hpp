#ifndef __PLUGIN__DEFAULTMANAGER__HPP__
#define __PLUGIN__DEFAULTMANAGER__HPP__

#include <plugin_core/Manager.hpp>
#include <vector>
#include <memory>

class QPluginLoader;

namespace plugin {

class DefaultManager : public Manager
{
public:
	DefaultManager();
	virtual ~DefaultManager();

	virtual void load(const QString& plugin_path) override;
	virtual void unload() override;

	virtual void register_renderer(const Plugin*, const Renderer*) override;
	virtual std::vector<const Renderer*> get_renderers() const override;

private:
	void load_plugin(const QString&);
	void dump_metadata(const QPluginLoader&) const;
	void unregister_renderers(const Plugin*);

	std::vector<std::shared_ptr<QPluginLoader>> plugins;
	std::vector<std::pair<const Plugin*, const Renderer*>> renderers;
};

}

#endif

