#ifndef __CHART_MODEL__HPP__
#define __CHART_MODEL__HPP__

#include <chart/ModelEntry.hpp>
#include <vector>

class ChartModel
{
public:
	virtual ~ChartModel();

	virtual std::vector<std::shared_ptr<chart::Chart>> get_charts() const;
	virtual std::vector<std::shared_ptr<chart::Renderer>> get_renderers() const;

	virtual void add(chart::ModelEntry);

private:
	std::vector<::chart::ModelEntry> charts;
};

#endif
