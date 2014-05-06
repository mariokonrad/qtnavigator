#ifndef __CHART__GSHHS__FACTORY__HPP__
#define __CHART__GSHHS__FACTORY__HPP__

#include <chart/Factory.hpp>

namespace chart {
namespace gshhs {

/// Factory for the GSHHS charts.
class Factory : public ::chart::Factory
{
public:
	virtual ~Factory();

	virtual chart::ModelEntry create(std::string) const override;
};

}}

#endif
