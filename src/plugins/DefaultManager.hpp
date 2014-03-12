#ifndef __PLUGINS__DEFAULTMANAGER__HPP__
#define __PLUGINS__DEFAULTMANAGER__HPP__

#include <plugins/Manager.hpp>
#include <vector>
#include <memory>

class QPluginLoader;

namespace plugins {

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

