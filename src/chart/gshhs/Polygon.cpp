#include "Polygon.hpp"

namespace chart {
namespace gshhs {

Polygon::Polygon()
	: id(0)
	, num(0)
	, flag(0)
	, west_ud(0)
	, east_ud(0)
	, south_ud(0)
	, north_ud(0)
	, area(0)
	, area_full(0)
	, container(0)
	, ancestor(0)
{
}

uint8_t Polygon::level() const
{
	// 1 land, 2 lake, 3 island_in_lake, 4 pond_in_island_in_lake
	return flag & 255;
}

uint8_t Polygon::version() const
{
	// Should be 12 for GSHHG release 12 (i.e., version 2.2)
	return (flag >> 8) & 255;
}

bool Polygon::greenwich() const
{
	// 1 if Greenwich is crossed
	return 0 != ((flag >> 16) & 1);
}

uint8_t Polygon::source() const
{
	// 0 = CIA WDBII, 1 = WVS
	return (flag >> 24) & 1;
}

uint8_t Polygon::river () const
{
	// 0 = not set, 1 = river-lake and level = 2
	return (flag >> 25) & 1;
}

}}
