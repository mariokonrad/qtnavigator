#include "Chart.hpp"

namespace chart {
namespace gshhs {

Chart::Chart()
{
}

Chart::~Chart()
{
}

std::size_t Chart::num_polygons() const
{
	return polygons.size();
}

}}
