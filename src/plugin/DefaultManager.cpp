#include "DefaultManager.hpp"
#include <plugin_core/Plugin.hpp>
#include <QString>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>

namespace plugin {

DefaultManager::DefaultManager()
{
}

DefaultManager::~DefaultManager()
{
}

void DefaultManager::load(const QString& plugin_path)
{
	QDir plugindir = QDir(plugin_path);
	for (auto filename : plugindir.entryList(QDir::Files | QDir::NoDotAndDotDot)) {
		QString path = plugindir.absoluteFilePath(filename);
		qDebug() << __PRETTY_FUNCTION__ << ":" << path;
		if (QLibrary::isLibrary(path)) {
			load_plugin(path);
		}
	}
}

void DefaultManager::dump_metadata(const QPluginLoader& loader) const
{
	const auto meta = loader.metaData();
	qDebug() << meta.value("MetaData").toObject().value("name");
	qDebug() << meta.value("MetaData").toObject().value("version");
	qDebug() << meta.value("MetaData").toObject().value("dependencies");
}

void DefaultManager::load_plugin(const QString& path)
{
	qDebug() << __PRETTY_FUNCTION__ << ":" << path;
	auto loader = std::make_shared<QPluginLoader>(path);
	dump_metadata(*loader);
	if (!loader->load()) {
		qDebug() << "ERROR: cannot load plugin: " << path;
		return;
	}
	Plugin* plugin = qobject_cast<Plugin*>(loader->instance());
	if (!plugin) {
		qDebug() << "failure: cannot instantiate plugin";
		return;
	}

	plugins.push_back(loader);
	qDebug() << "SUCCESS: loaded";
	qDebug() << "name: " << plugin->name();
	plugin->setup();
}

void DefaultManager::unload()
{
	for (auto loader : plugins) {
		Plugin* plugin = qobject_cast<Plugin*>(loader->instance());

		plugin->terminate();
		unregister_renderers(plugin);

		plugin->cleanup();
		loader->unload();
		loader.reset();
	}
}

void DefaultManager::unregister_renderers(const Plugin* plugin)
{
	using namespace std;

	renderers.erase(remove_if(begin(renderers), end(renderers),
							  [=](const pair<const Plugin*, const Renderer*>& item) {
						return item.first == plugin;
					}),
					renderers.end());
}

void DefaultManager::register_renderer(const Plugin* plugin, const Renderer* renderer)
{
	renderers.push_back(std::make_pair(plugin, renderer));
}

std::vector<const Renderer*> DefaultManager::get_renderers() const
{
	using namespace std;

	vector<const Renderer*> v;
	v.reserve(renderers.size());
	for (auto const& renderer : renderers) {
		v.push_back(renderer.second);
	}

	return v;
}

}
