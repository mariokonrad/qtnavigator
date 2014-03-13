#include "Reader.hpp"
#include <chart/gshhs/Polygon.hpp>
#include <chart/gshhs/Chart.hpp>
#include <utils/endian.hpp>
#include <fstream>
#include <QDebug>

namespace chart {
namespace gshhs {

/// Reads a signed integer value from the stream and converts it
/// from big endian to host endianess.
void Reader::read_bigendian(std::istream& is, int32_t& data) const
{
	is.read(reinterpret_cast<char*>(&data), sizeof(data));
	data = endian::ntoh(data);
}

/// Reads a signed integer value from the stream and converts it
/// from big endian to host endianess.
void Reader::read_bigendian(std::istream& is, uint32_t& data) const
{
	is.read(reinterpret_cast<char*>(&data), sizeof(data));
	data = endian::ntoh(data);
}

/// Reads the file, specified by the path.
void Reader::read(std::string path, Chart& chart) const
{
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary);

	if (!ifs.is_open()) {
		return;
	}
	while (!ifs.eof()) {
		Polygon poly;
		read_polygon(ifs, poly);
		chart.polygons.push_back(poly);
	}
}

/// Reads a polygon from the spefied stream.
void Reader::read_polygon(std::istream& is, Polygon& poly) const
{
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
		int32_t lon_ud = 0;
		int32_t lat_ud = 0;

		read_bigendian(is, lon_ud);
		read_bigendian(is, lat_ud);

		double lat = 1.0e-6 * lat_ud;
		double lon = 1.0e-6 * lon_ud;

		// this conversion was taken from original source gshhg.c (gmt version 5.1.1)
		if ((poly.greenwich() && (lon > 270.0)) || (poly.west_ud > 180000000)) {
			lon -= 360.0;
		}

		poly.points.emplace_back(lat, lon);
	}
}

}}
