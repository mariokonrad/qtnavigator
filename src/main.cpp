#include <MainWindow.hpp>
#include <chart/gshhs/Reader.hpp> // TEMP
#include <chart/gshhs/Chart.hpp> // TEMP
#include <plugin/DefaultManager.hpp>
#include <QApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QApplication::setApplicationName("qtnavigator");
	QApplication::setApplicationVersion("0.0.1"); // TODO: replace with version provided by cmake

	QString data_root = QDir(app.applicationDirPath() + "/../share/" + app.applicationName() + "/").absolutePath();
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

	plugin::DefaultManager plugins;
	plugins.load(plugin_path);
	plugins.unload();

	auto chart_model = std::make_shared<ChartModel>();

	// TEMP: this does not belong here, just temporary
	std::shared_ptr<chart::gshhs::Chart> chart = std::make_shared<chart::gshhs::Chart>();
	chart::gshhs::Reader reader;
	reader.read(data_root.toStdString() + "/gshhs/gshhs_c.b", *chart);
	qDebug() << "num polys = " << chart->num_polygons();
	chart_model->add(chart);

	MainWindow window(chart_model);
	window.show();
	return app.exec();
}
