#include "MapWidget.hpp"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

MapWidget::MapWidget(QWidget* parent)
    : QWidget(parent)
{
	setMinimumSize(300, 200);

	// receive mouseMoveEvent even if not pressed. this is useful to
	// track the position of the mouse cursor to display position for
	// example.
	setMouseTracking(true);
}

void MapWidget::paintEvent(QPaintEvent* event)
{
	QBrush background(QColor(224, 224, 224));
	QPen pen(Qt::black);

	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.fillRect(event->rect(), background);
	painter.setPen(pen);
	painter.drawLine(0, 0, width() - 1, height() - 1);

	painter.end();
}

void MapWidget::mouseMoveEvent(QMouseEvent* event)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::mousePressEvent(QMouseEvent* event)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::mouseReleaseEvent(QMouseEvent* event)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::wheelEvent(QWheelEvent* event)
{
	qDebug() << __PRETTY_FUNCTION__;
}

