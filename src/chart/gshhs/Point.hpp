#ifndef __CHART__GSHHS__POINT__HPP__
#define __CHART__GSHHS__POINT__HPP__

namespace chart {
namespace gshhs {

class Point
{
public:
	Point(double lat, double lon);

	const double lat;
	const double lon;
};

}}

#endif
