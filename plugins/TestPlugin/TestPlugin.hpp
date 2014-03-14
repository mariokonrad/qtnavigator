#ifndef __PLUGINS__TESTPLUGIN__TESTPLUGIN__HPP__
#define __PLUGINS__TESTPLUGIN__TESTPLUGIN__HPP__

#include <plugin_core/Plugin.hpp>

namespace plugins {
namespace testplugin {

class TestPlugin : public QObject, virtual public plugin::Plugin
{
	Q_OBJECT
	Q_INTERFACES(plugin::Plugin)
	Q_PLUGIN_METADATA(IID "qtnavigator.PluginInterface/1.0" FILE "TestPlugin.json")

public:
	TestPlugin();
	virtual ~TestPlugin();

	virtual QString name() const;
	virtual void setup();
	virtual void cleanup();
};

}}

#endif
