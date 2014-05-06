#ifndef __CHART__GSHHS__RENDERER__HPP__
#define __CHART__GSHHS__RENDERER__HPP__

#include <chart/Renderer.hpp>

namespace chart {
namespace gshhs {

class Chart;

/// Renderer for GSHHS charts.
class Renderer : public ::chart::Renderer
{
public:
	Renderer(const Chart&);
	virtual ~Renderer();

	virtual void render(QPainter&, Context) const;

private:
	const Chart& chart;
};

}}

#endif
