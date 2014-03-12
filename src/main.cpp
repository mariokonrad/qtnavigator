#include <MainWindow.hpp>
#include <plugins/DefaultManager.hpp>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

	plugins::DefaultManager plugins;
	plugins.load(app.applicationDirPath() + "/../lib/");
	plugins.unload();

    MainWindow window;
    window.show();
    return app.exec();
}
