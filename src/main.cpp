#include <MainWindow.hpp>
#include <ChartModel.hpp>
#include <global/Registry.hpp>
#include <chart/gshhs/Factory.hpp>
#include <chart/FactoryRegistry.hpp>
#include <plugin/DefaultManager.hpp>
#include <version.h>
#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QApplication::setApplicationName("qtnavigator");
	QApplication::setApplicationVersion(
		QString("%1.%2.%3").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_PATCH));

	QString data_root = QDir(app.applicationDirPath() + "/../share/" + app.applicationName() + "/")
							.absolutePath();
	QString plugin_path = QDir(app.applicationDirPath() + "/../lib/plugins/").absolutePath();

	qDebug() << "1 ApplicationDirPath: " << data_root;
	qDebug() << "1 Plugin Path       : " << plugin_path;

	QCommandLineParser parser;
	parser.setApplicationDescription("qtnavigator");
	parser.addHelpOption();
	parser.addVersionOption();

	QCommandLineOption option_data_root("data-root", "Set data root directory.", "directory",
										data_root);
	parser.addOption(option_data_root);
	QCommandLineOption option_plugin_dir("plugin-dir", "Specify the plugin directory.", "directory",
										 plugin_path);
	parser.addOption(option_plugin_dir);

	parser.process(app);

	data_root = parser.value(option_data_root);
	plugin_path = parser.value(option_plugin_dir);
	qDebug() << "2 ApplicationDirPath: " << data_root;
	qDebug() << "2 Plugin Path       : " << plugin_path;

	auto plugins = std::make_shared<plugin::DefaultManager>();
	global::Registry::get().inject(plugins);
	plugins->load(plugin_path);

	auto chart_model = std::make_shared<ChartModel>();

	chart::FactoryRegistry factories;
	factories.add("gshhs", std::make_shared<chart::gshhs::Factory>());

	chart_model->add(factories.create("gshhs", data_root.toStdString() + "/gshhs/gshhs_c.b"));

	MainWindow window(chart_model);
	window.show();
	int rc = app.exec();

	plugins->unload();

	return rc;
}
