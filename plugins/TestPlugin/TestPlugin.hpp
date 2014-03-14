#ifndef __PLUGINS__TESTPLUGIN__TESTPLUGIN__HPP__
#define __PLUGINS__TESTPLUGIN__TESTPLUGIN__HPP__

#include <plugins/Plugin.hpp>

namespace plugins {
namespace testplugin {

class TestPlugin : public QObject, virtual public plugins::Plugin
{
	Q_OBJECT
	Q_INTERFACES(plugins::Plugin)
	Q_PLUGIN_METADATA(IID "qttmp.PluginInterface/0.1" FILE "TestPlugin.json")

public:
	TestPlugin();
	virtual ~TestPlugin();

	virtual QString name() const;
	virtual void setup();
	virtual void cleanup();
};

}}

#endif
