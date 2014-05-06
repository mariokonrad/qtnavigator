#include "ChartModel.hpp"

ChartModel::~ChartModel()
{
}

std::vector<std::shared_ptr<chart::Chart>> ChartModel::get_charts() const
{
	std::vector<std::shared_ptr<chart::Chart>> v;
	v.reserve(charts.size());
	for (auto const entry : charts) {
		v.push_back(entry.chart);
	}
	return v;
}

std::vector<std::shared_ptr<chart::Renderer>> ChartModel::get_renderers() const
{
	std::vector<std::shared_ptr<chart::Renderer>> v;
	v.reserve(charts.size());
	for (auto const entry : charts) {
		v.push_back(entry.renderer);
	}
	return v;
}

void ChartModel::add(::chart::ModelEntry entry)
{
	charts.push_back(entry);
}

