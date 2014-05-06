#ifndef __CHART__CHART__HPP__
#define __CHART__CHART__HPP__

#include <memory>

namespace chart {

class Renderer;

/// The base class of all charts.
///
/// The charts do not know how to render, this is what renderers are for.
/// Each chart returns an appropriate renderer.
class Chart
{
public:
	virtual ~Chart();
};

}

#endif
