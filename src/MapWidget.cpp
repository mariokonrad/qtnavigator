#include "MapWidget.hpp"
#include <chart/Renderer.hpp>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

MapWidget::MapWidget(QWidget* parent)
    : QWidget(parent)
	, panning(false)
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

	// TODO: temporary data about view (position and zoom)
	chart::Renderer::Context context{
		width(), height(),
		geo::Position{ 0.0, 0.0 },
		+90.0, -90.0,
		-180.0, +180.0,
		1
	};

	for (const auto renderer : chart_model->get_renderers()) {
		renderer->render(painter, context);
	}

	painter.end();
}

void MapWidget::mouseMoveEvent(QMouseEvent*)
{
	qDebug() << __PRETTY_FUNCTION__;

	if (panning) {
		// TODO: pan chart
	}

	// TODO: update curos position on status bar
}

void MapWidget::mousePressEvent(QMouseEvent* event)
{
	qDebug() << __PRETTY_FUNCTION__;

	// TODO: there will be other actions as well, not just panning

	if (event && event->button() == Qt::LeftButton) {
		panning = true;
	}
}

void MapWidget::mouseReleaseEvent(QMouseEvent* event)
{
	qDebug() << __PRETTY_FUNCTION__;

	if (event && event->button() == Qt::LeftButton) {
		panning = false;
	}
}

void MapWidget::wheelEvent(QWheelEvent*)
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::zoom_in()
{
	qDebug() << __PRETTY_FUNCTION__;
}

void MapWidget::zoom_out()
{
	qDebug() << __PRETTY_FUNCTION__;
}

