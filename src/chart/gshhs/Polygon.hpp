#ifndef __CHART__GSHHS__POLYGON__HPP__
#define __CHART__GSHHS__POLYGON__HPP__

#include <chart/gshhs/Point.hpp>
#include <vector>
#include <stdint.h>

namespace chart {
namespace gshhs {

/// Contains data from GSHHS polygon data.
///
/// This class is built by the reader facility.
class Polygon
{
	friend class Reader;

public:
	Polygon();

	uint8_t level() const;
	uint8_t version() const;
	bool greenwich() const;
	uint8_t source() const;
	uint8_t river () const;
	uint8_t area_mag() const;

	std::size_t size() const;
	const std::vector<Point>& get_points() const; // TEMP

private:
	std::vector<Point> points;

	// data types of the polygon attribtes, directly from gshhs.h (gmt version 5.1.1)

	uint32_t id; //< unique polygon id number, starting at 0
	uint32_t num; //< number of points
	uint32_t flag; //< level + version << 8 + greenwich << 16 + source << 24

	// min/max extent in micro degrees
	int32_t west_ud;
	int32_t east_ud;
	int32_t south_ud;
	int32_t north_ud;

	uint32_t area; //< area of polygon in 1/10 km^2
	uint32_t area_full; //< area of original full-resolution polygon in 1/10 km^2
	int32_t container; //< id of container polygon that encolses this polygin, -1 if none

	// id of ancestor polygon in the full resolution set that was the
	// source of this polygon, -1 if none
	int32_t ancestor;
};

}}

#endif
