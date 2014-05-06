#ifndef __CHART__FACTORY__HPP__
#define __CHART__FACTORY__HPP__

#include <chart/ModelEntry.hpp>

namespace chart {

/// Base class for chart factories.
class Factory
{
public:
	virtual ~Factory();

	virtual chart::ModelEntry create(std::string) const = 0;
};

}

#endif
