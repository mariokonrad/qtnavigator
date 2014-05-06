#ifndef __MAPWIDGET__HPP__
#define __MAPWIDGET__HPP__

#include <ChartModel.hpp>
#include <QWidget>

class MapWidget : public QWidget
{
	Q_OBJECT

public:
	MapWidget(QWidget* parent);
	void set(std::shared_ptr<ChartModel>);

protected:
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
	virtual void mouseReleaseEvent(QMouseEvent* event);
	virtual void wheelEvent(QWheelEvent* event);

private:
	std::shared_ptr<ChartModel> chart_model;
};

#endif
