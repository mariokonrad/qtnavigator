#ifndef __CHART__GSHHS__POINT__HPP__
#define __CHART__GSHHS__POINT__HPP__

namespace chart {
namespace gshhs {

/// This is a point read from GSHHS data, represented
/// by latitude, longitude.
class Point
{
public:
	Point(double lat, double lon);

	const double lat;
	const double lon;
};

}}

#endif
