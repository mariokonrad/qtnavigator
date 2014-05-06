#include "Factory.hpp"
#include <chart/gshhs/Reader.hpp>
#include <chart/gshhs/Chart.hpp>
#include <chart/gshhs/Renderer.hpp>
#include <QDebug>

namespace chart {
namespace gshhs {

Factory::~Factory()
{
}

chart::ModelEntry Factory::create(std::string path) const
{
	std::shared_ptr<chart::gshhs::Chart> chart = std::make_shared<chart::gshhs::Chart>();
	chart::gshhs::Reader reader;
	reader.read(path, *chart);
	qDebug() << "num polys = " << chart->num_polygons();

	return { chart, std::make_shared<Renderer>(*chart) };
}

}}

