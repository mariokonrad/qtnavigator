#ifndef __CHART_MODEL__HPP__
#define __CHART_MODEL__HPP__

#include <memory>
#include <vector>

namespace chart {
class Chart;
class Renderer;
}

class ChartModel
{
public:
	virtual ~ChartModel();

	virtual std::vector<std::shared_ptr<chart::Chart>> get_charts() const;
	virtual std::vector<std::shared_ptr<chart::Renderer>> get_renderers() const;

	virtual void add(std::shared_ptr<chart::Chart>);

private:
	std::vector<std::shared_ptr<chart::Chart>> charts;
};

#endif
