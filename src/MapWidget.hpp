#ifndef __MAPWIDGET__HPP__
#define __MAPWIDGET__HPP__

#include <chart/gshhs/Chart.hpp> // TEMP
#include <QWidget>

class MapWidget : public QWidget
{
	Q_OBJECT

public:
	MapWidget(QWidget* parent, std::string data_root);

protected:
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void wheelEvent(QWheelEvent* event);

private:
	chart::gshhs::Chart chart; // TEMP
};

#endif
