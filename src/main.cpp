#include <MainWindow.hpp>
#include <plugins/DefaultManager.hpp>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	qDebug() << "ApplicationDirPath: " << app.applicationDirPath();

	plugins::DefaultManager plugins;
	plugins.load(app.applicationDirPath() + "/../lib/");
	plugins.unload();

	MainWindow window;
	window.show();
	return app.exec();
}
