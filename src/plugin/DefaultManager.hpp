#ifndef __PLUGIN__DEFAULTMANAGER__HPP__
#define __PLUGIN__DEFAULTMANAGER__HPP__

#include <plugin/Manager.hpp>
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

private:
	void load_plugin(const QString&);
	void dump_metadata(const QPluginLoader&) const;

	std::vector<std::shared_ptr<QPluginLoader>> plugins;
};

}

#endif

