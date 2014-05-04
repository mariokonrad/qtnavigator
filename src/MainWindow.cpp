#include "MainWindow.hpp"
#include <MapWidget.hpp>
#include <action/ExitApplication.hpp>
#include <action/Fullscreen.hpp>
#include <action/About.hpp>
#include <action/AboutQt.hpp>
#include <QMenuBar>
#include <QMessageBox>

MainWindow::MainWindow(std::string data_root)
	: menu_file(nullptr)
	, menu_view(nullptr)
	, menu_help(nullptr)
	, action_exit(nullptr)
	, action_toggle_fullscreen(nullptr)
	, action_about(nullptr)
	, action_about_qt(nullptr)
	, map_widget(nullptr)
{
	setWindowTitle(tr("qtnavigator"));

	create_actions();
	create_menus();
	create_statusbar();

	map_widget = new MapWidget(this, data_root);

	setCentralWidget(map_widget);
}

void MainWindow::create_statusbar()
{
	statusBar();
}

void MainWindow::create_menus()
{
	menu_file = menuBar()->addMenu(tr("&File"));
	menu_file->addAction(action_exit);

	menu_view = menuBar()->addMenu(tr("&View"));
	menu_view->addAction(action_toggle_fullscreen);

	menu_help = menuBar()->addMenu(tr("&Help"));
	menu_help->addAction(action_about);
	menu_help->addAction(action_about_qt);
}

void MainWindow::create_actions()
{
	action_exit = new action::ExitApplication(this);
	connect(action_exit, SIGNAL(triggered()), this, SLOT(close()));

	action_toggle_fullscreen = new action::Fullscreen(this);
	connect(action_toggle_fullscreen, SIGNAL(showFullScreen()), this, SLOT(showFullScreen()));
	connect(action_toggle_fullscreen, SIGNAL(showNormal()), this, SLOT(showNormal()));

	action_about = new action::About(this);
	connect(action_about, SIGNAL(triggered()), this, SLOT(on_about()));

	action_about_qt = new action::AboutQt(this);
	connect(action_about_qt, SIGNAL(triggered()), this, SLOT(on_about_qt()));
}

void MainWindow::on_about()
{
	QMessageBox::about(this, "qtnavigator", "qtnavigator : navigation software");
}

void MainWindow::on_about_qt()
{
	QMessageBox::aboutQt(this, "qtnavigator");
}

