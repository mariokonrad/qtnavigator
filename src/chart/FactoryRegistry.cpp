#include "FactoryRegistry.hpp"
#include <chart/Factory.hpp>

namespace chart {

void FactoryRegistry::add(std::string id, std::shared_ptr<Factory> factory)
{
	factories[id] = factory;
}

ModelEntry FactoryRegistry::create(std::string type, std::string path) const
{
	auto factory = factories.find(type);
	if (factory == factories.end())
		return ModelEntry();
	return factory->second->create(path);
}

}

