#include "MapWidget.hpp"
#include <chart/Renderer.hpp>
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
}

void MapWidget::set(std::shared_ptr<ChartModel> model)
{
	chart_model = model;
}

void MapWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillRect(event->rect(), QBrush(QColor(255, 255, 255)));
	painter.setPen(QPen(Qt::black));

	chart::Renderer::Context context{ width(), height() };

	for (const auto renderer : chart_model->get_renderers()) {
		renderer->render(painter, context);
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

