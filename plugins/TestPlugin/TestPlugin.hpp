#ifndef __PLUGINS__TESTPLUGIN__TESTPLUGIN__HPP__
#define __PLUGINS__TESTPLUGIN__TESTPLUGIN__HPP__

#include <plugin_core/Plugin.hpp>
#include <plugin_core/Renderer.hpp>

namespace plugins {
namespace testplugin {

class TestPlugin
	: public QObject
	, virtual public ::plugin::Plugin
	, virtual public ::plugin::Renderer
{
	Q_OBJECT
	Q_INTERFACES(plugin::Plugin)
	Q_PLUGIN_METADATA(IID "qtnavigator.PluginInterface/1.0" FILE "TestPlugin.json")

public:
	TestPlugin();
	virtual ~TestPlugin();

public: // Plugin
	virtual QString name() const override;
	virtual void setup() override;
	virtual void cleanup() override;

public: // Renderer
	virtual void render(QPainter&) const override;
};

}}

#endif
