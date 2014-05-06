#ifndef __CHART__MODELENTRY__HPP__
#define __CHART__MODELENTRY__HPP__

#include <memory>

namespace chart {

class Chart;
class Renderer;

struct ModelEntry
{
	std::shared_ptr<::chart::Chart> chart;
	std::shared_ptr<::chart::Renderer> renderer;
};

}

#endif
