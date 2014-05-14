#include "range.hpp"
#include <utility>

namespace math {

/// Returns a the wrapped value between (and inclusive) the specified bounds.
///
/// @note This implementation uses loops, it is very inefficient for values
///       that differ much from the target interval.
double range_bounds(double value, double lower_bound, double upper_bound)
{
	if (lower_bound > upper_bound)
		std::swap(lower_bound, upper_bound);

	//return fmod(value - lower_bound, upper_bound - lower_bound) + lower_bound;

	const double range = upper_bound - lower_bound;
	if (range == 0.0)
		return upper_bound;
	while (value < lower_bound)
		value += range;
	while (value > upper_bound)
		value -= range;
	return value;
}

}

