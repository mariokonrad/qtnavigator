#include "Chart.hpp"
#include <chart/gshhs/Renderer.hpp>

namespace chart {
namespace gshhs {

Chart::Chart()
{
}

Chart::~Chart()
{
}

std::shared_ptr<::chart::Renderer> Chart::get_renderer()
{
	return std::make_shared<Renderer>(*this);
}

std::size_t Chart::num_polygons() const
{
	return polygons.size();
}

const std::vector<Polygon>& Chart::get_polygons() const
{
	return polygons;
}

}}
