#ifndef __CHART__RENDERER__HPP__
#define __CHART__RENDERER__HPP__

class QPainter;

namespace chart {

/// Interface for all chart renderers.
class Renderer
{
public:
	struct Context {
		int width;
		int height;
		// TODO: lat/lon
	};

	virtual ~Renderer();

	virtual void render(QPainter&, Context) const = 0;
};

}

#endif
