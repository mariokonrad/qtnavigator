#include "ChartModel.hpp"
#include <chart/Chart.hpp>

ChartModel::~ChartModel()
{
}

std::vector<std::shared_ptr<chart::Chart>> ChartModel::get_charts() const
{
	return charts;
}

void ChartModel::add(std::shared_ptr<chart::Chart> chart)
{
	charts.push_back(chart);
}

std::vector<std::shared_ptr<chart::Renderer>> ChartModel::get_renderers() const
{
	std::vector<std::shared_ptr<chart::Renderer>> v;
	for (auto const chart : charts) {
		v.push_back(chart->get_renderer());
	}
	return v;
}

