#include "Renderer.hpp"
#include <chart/gshhs/Chart.hpp>
#include <QPainter>

namespace chart {
namespace gshhs {

Renderer::Renderer(const Chart& chart)
	: chart(chart)
{
}

Renderer::~Renderer()
{
}

void Renderer::render(QPainter& painter, Context ctx) const
{
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
			int x = ctx.width * (point.lon + 180.0) / 360.0;
			int y = ctx.height - ctx.height * (point.lat + 90.0) / 180.0;

			poly.setPoint(index, x, y);
			++index;
		}

		painter.drawPolygon(poly);
	}
}

}}

