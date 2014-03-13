#ifndef __CHART__GSHHS__CHART__HPP__
#define __CHART__GSHHS__CHART__HPP__

#include <chart/gshhs/Polygon.hpp>

namespace chart {
namespace gshhs {

/// Holds data of GSHHS charts.
///
/// Is initialized by the reader facility.
class Chart
{
	friend class Reader;

public:
	Chart();
	virtual ~Chart();

	std::size_t num_polygons() const;
	const std::vector<Polygon>& get_polygons() const; // TEMP

private:
	std::vector<Polygon> polygons;
};

}}

#endif
