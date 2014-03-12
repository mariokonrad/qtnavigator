#include "DefaultManager.hpp"
#include <plugins/Plugin.hpp>
#include <QString>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>

namespace plugins {

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
		qDebug() << path;
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
	auto loader = std::make_shared<QPluginLoader>(path);
	dump_metadata(*loader);
	if (!loader->load()) {
		qDebug() << "ERROR: cannot load plugin";
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
		plugin->cleanup();
		loader->unload();
		loader.reset();
	}
}

}
