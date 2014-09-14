#include "MainWindow.hpp"
#include <MapWidget.hpp>
#include <action/ExitApplication.hpp>
#include <action/Fullscreen.hpp>
#include <action/About.hpp>
#include <action/AboutQt.hpp>
#include <action/ZoomIn.hpp>
#include <action/ZoomOut.hpp>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>

MainWindow::MainWindow(std::shared_ptr<ChartModel> chart_model)
	: menu_file(nullptr)
	, menu_view(nullptr)
	, menu_help(nullptr)
	, toolbar(nullptr)
	, action_exit(nullptr)
	, action_toggle_fullscreen(nullptr)
	, action_about(nullptr)
	, action_about_qt(nullptr)
	, action_zoom_in(nullptr)
	, action_zoom_out(nullptr)
	, map_widget(nullptr)
	, chart_model(chart_model)
{
	setWindowTitle(tr("qtnavigator"));

	map_widget = new MapWidget(this);
	map_widget->set(chart_model);

	create_actions();
	create_menus();
	create_statusbar();
	create_toolbar();

	setCentralWidget(map_widget);
}

void MainWindow::create_statusbar()
{
	statusBar();
}

void MainWindow::create_toolbar()
{
	toolbar = addToolBar(tr("Toolbar"));

	// TODO: populate toolbar
	toolbar->addAction(action_toggle_fullscreen);
	toolbar->addAction(action_zoom_in);
	toolbar->addAction(action_zoom_out);
}

void MainWindow::create_menus()
{
	menu_file = menuBar()->addMenu(tr("&File"));
	menu_file->addAction(action_exit);

	menu_view = menuBar()->addMenu(tr("&View"));
	menu_view->addAction(action_toggle_fullscreen);
	menu_view->addSeparator();
	menu_view->addAction(action_zoom_in);
	menu_view->addAction(action_zoom_out);

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

	action_zoom_in = new action::ZoomIn(this);
	connect(action_zoom_in, SIGNAL(triggered()), map_widget, SLOT(zoom_in()));

	action_zoom_out = new action::ZoomOut(this);
	connect(action_zoom_out, SIGNAL(triggered()), map_widget, SLOT(zoom_out()));
}

void MainWindow::on_about()
{
	QMessageBox::about(this, "qtnavigator", "qtnavigator : navigation software");
}

void MainWindow::on_about_qt()
{
	QMessageBox::aboutQt(this, "qtnavigator");
}

