#include "MapWidget.hpp"
#include <chart/gshhs/Reader.hpp> // TEMP
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

MapWidget::MapWidget(QWidget* parent)
    : QWidget(parent)
{
	setMinimumSize(360, 180);

	// receive mouseMoveEvent even if not pressed. this is useful to
	// track the position of the mouse cursor to display position for
	// example.
	setMouseTracking(true);

	// TEMP: this does not belong here, just temporary
	chart::gshhs::Reader reader;
	reader.read("data/gshhs/gshhs_c.b", chart);
	qDebug() << "num polys = " << chart.num_polygons();
}

void MapWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillRect(event->rect(), QBrush(QColor(255, 255, 255)));
	painter.setPen(QPen(Qt::black));

	// TEMP: draw polygons from chart
	for (const auto& polygon : chart.get_polygons()) {
		if (polygon.level() != 1) {
			// draw only land, for now
			continue;
		}
		QPolygon poly(polygon.size());
		int index = 0;
		for (const auto& point : polygon.get_points()) {
			// TODO: calc x/y coordinates, using projection.
			//       for now, it is always scaled to the entire widget
			int x = width() * (point.lon + 180.0) / 360.0;
			int y = height() - height() * (point.lat + 90.0) / 180.0;

			poly.setPoint(index, x, y);
			++index;
		}

		painter.drawPolygon(poly);
	}

	painter.end();
}

void MapWidget::mouseMoveEvent(QMouseEvent*)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::mousePressEvent(QMouseEvent*)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::mouseReleaseEvent(QMouseEvent*)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::wheelEvent(QWheelEvent*)
{
	qDebug() << __PRETTY_FUNCTION__;
}

