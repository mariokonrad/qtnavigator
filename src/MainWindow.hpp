#ifndef __MAINWINDOW__H__
#define __MAINWINDOW__H__

#include <QMainWindow>

class MapWidget;
class QMenu;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private slots:
	void on_about();
	void on_about_qt();

private:
	void create_actions();
	void create_menus();
	void create_statusbar();

	QMenu* menu_file;
	QMenu* menu_view;
	QMenu* menu_help;
	QAction* action_exit;
	QAction* action_toggle_fullscreen;
	QAction* action_about;
	QAction* action_about_qt;
	MapWidget* map_widget;
};

#endif
