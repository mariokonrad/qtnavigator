#ifndef __CHART__RENDERER__HPP__
#define __CHART__RENDERER__HPP__

#include <geo/Position.hpp>

class QPainter;

namespace chart {

/// Interface for all chart renderers.
class Renderer
{
public:
	/// Context to render charts. This structure may contain redundant information,
	/// but this is for convenience.
	struct Context
	{
		int width; // width of the drawing context
		int height; // height of the drawing context

		geo::Position center; // center of view

		geo::Position::Latitude lat_top; // latitude of the top border of the region to render.
		geo::Position::Latitude  lat_bottom; // latitude of the bottom border of the region to render.
		geo::Position::Longitude lon_left; // longitude of the left border of the region to render.
		geo::Position::Longitude lon_right; // longitude of the right border of the region to render.

		int scale; // scale to render the content
	};

	virtual ~Renderer();

	virtual void render(QPainter&, Context) const = 0;
};

}

#endif
