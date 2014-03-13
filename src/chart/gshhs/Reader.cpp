#include "Reader.hpp"
#include <chart/gshhs/Polygon.hpp>
#include <utils/endian.hpp>
#include <fstream>

namespace chart {
namespace gshhs {

/// Reads a signed integer value from the stream and converts it
/// from big endian to host endianess.
void Reader::read_bigendian(std::istream& is, int32_t& data) const
{
	is.read(reinterpret_cast<char*>(&data), sizeof(data));
	data = endian::ntoh(data);
}

/// Reads the file, specified by the path.
void Reader::read(std::string path) const
{
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		return;
	}
	while (!ifs.eof()) {
		read_polygon(ifs);
	}
}

/// Reads a polygon from the spefied stream.
void Reader::read_polygon(std::istream& is) const
{
	Polygon poly;

	read_bigendian(is, poly.id);
	read_bigendian(is, poly.num);
	read_bigendian(is, poly.flag);
	read_bigendian(is, poly.west_ud);
	read_bigendian(is, poly.east_ud);
	read_bigendian(is, poly.south_ud);
	read_bigendian(is, poly.north_ud);
	read_bigendian(is, poly.area);
	read_bigendian(is, poly.area_full);
	read_bigendian(is, poly.container);
	read_bigendian(is, poly.ancestor);

	poly.points.reserve(poly.num);
	for (int32_t i = 0; i < poly.num; ++i) {
		int32_t x = 0;
		int32_t y = 0;

		read_bigendian(is, x);
		read_bigendian(is, y);

		poly.points.emplace_back(x * 1.0e-6, y * 1.0e-6);
	}
}

}}
