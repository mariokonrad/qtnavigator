#include "Plugin.hpp"
#include <Renderer.hpp>
#include <Manager.hpp>
#include <Registry.hpp>
#include <QDebug>

namespace plugin {

Plugin::~Plugin() {}

void Plugin::register_renderer(const Renderer* renderer)
{
	qDebug() << __PRETTY_FUNCTION__;
	Registry::get().plugins()->register_renderer(this, renderer);
}

/// This method is to notify the plugin to terminate. If the plugin
/// has active elements (e.g. threads, etc.), this is the point for
/// the plugin to stop activities.
/// This mechanism allows the plugin to terminate gracefully, the
/// application trusts the plugin to behave well.
/// The cleanup code may remain within the 'cleanup' method of the plugin,
/// to finally release resources. This method also gets called before
/// the unregistering of the plugin's interfaces takes place. This is
/// to ensure that no activities that requires registrations breaks, since
/// all registrations of a plugin are removed automatically, once it is unloaded.
void Plugin::terminate()
{
	qDebug() << __PRETTY_FUNCTION__;
}

void test_dump()
{
	qDebug() << __PRETTY_FUNCTION__;
}

}

