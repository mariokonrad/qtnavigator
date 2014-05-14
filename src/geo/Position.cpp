#include "Position.hpp"
#include <utils/range.hpp>

namespace geo {

Position::Position(Latitude lat, Longitude lon)
	: latitude(lat)
	, longitude(lon)
{
}

Position::Latitude Position::lat() const
{
	return latitude;
}

Position::Longitude Position::lon() const
{
	return longitude;
}

/// Returns a normalized position. This means latitude in the interval [-90 .. +90],
/// longitude in the interval [-180 .. +180].
Position Position::normalize() const
{
	return Position{math::range_bounds(lat(), -90.0, +90.0),
					math::range_bounds(lon(), -180.0, +180.0)};
}

}

