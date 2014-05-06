#ifndef __CHART__FACTORYREGISTRY__HPP__
#define __CHART__FACTORYREGISTRY__HPP__

#include <chart/ModelEntry.hpp>
#include <map>
#include <string>

namespace chart {

class Factory;

class FactoryRegistry
{
public:
	void add(std::string, std::shared_ptr<Factory>);
	ModelEntry create(std::string, std::string) const;

private:
	std::map<std::string, std::shared_ptr<Factory>> factories;
};

}

#endif
