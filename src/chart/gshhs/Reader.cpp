#include "Reader.hpp"
#include <chart/gshhs/Point.hpp>
#include <utils/endian.hpp>
#include <fstream>
#include <iostream>

namespace chart {
namespace gshhs {

void Reader::read_bigendian(std::istream& is, int32_t& data)
{
	is.read(reinterpret_cast<char*>(&data), sizeof(data));
	data = endian::ntoh(data);
}

void Reader::read(std::string path)
{
	std::fstream ifs(path.c_str(), std::ios::in | std::ios::binary);

	std::cout << "path      = " << path << std::endl;
	while (!ifs.eof()) {
		read_polygon(ifs);
	}
}

void Reader::read_polygon(std::istream& is)
{
	int32_t id = 0; // unique polygon id number, starting at 0
	int32_t num = 0; // number of points
	int32_t flag = 0; // level + version << 8 + greenwich << 16 + source << 24

	// min/max extent in micro degrees
	int32_t west_ud = 0;
	int32_t east_ud = 0;
	int32_t south_ud = 0;
	int32_t north_ud = 0;

	int32_t area = 0; // area of polygon in 1/10 km^2
	int32_t area_full = 0; // area of original full-resolution polygon in 1/10 km^2
	int32_t container = 0; // id of container polygon that encolses this polygin, -1 if none

	// id of ancestor polygon in the full resolution set that was the
	// source of this polygon, -1 if none
	int32_t ancestor = 0;

	read_bigendian(is, id);
	read_bigendian(is, num);
	read_bigendian(is, flag);
	read_bigendian(is, west_ud);
	read_bigendian(is, east_ud);
	read_bigendian(is, south_ud);
	read_bigendian(is, north_ud);
	read_bigendian(is, area);
	read_bigendian(is, area_full);
	read_bigendian(is, container);
	read_bigendian(is, ancestor);

	uint8_t level = flag & 255; // 1 land, 2 lake, 3 island_in_lake, 4 pond_in_island_in_lake
	uint8_t version = (flag >> 8) & 255; // Should be 12 for GSHHG release 12 (i.e., version 2.2)
	uint8_t greenwich = (flag >> 16) & 1; // 1 if Greenwich is crossed
	uint8_t source = (flag >> 24) & 1; // 0 = CIA WDBII, 1 = WVS
	uint8_t river = (flag >> 25) & 1; // 0 = not set, 1 = river-lake and level = 2

	using namespace std;
/*
	cout << "id        = " << id << endl;
	cout << "num       = " << num << endl;
	cout << "level     = " << static_cast<int>(level) << endl;
	cout << "version   = " << static_cast<int>(version) << endl;
	cout << "flag      = " << flag << endl;
	cout << "west_ud   = " << 1.0e-6 * west_ud << endl;
	cout << "east_ud   = " << 1.0e-6 * east_ud << endl;
	cout << "south_ud  = " << 1.0e-6 * south_ud << endl;
	cout << "north_ud  = " << 1.0e-6 * north_ud << endl;
	cout << "area      = " << area << endl;
	cout << "area_full = " << area_full << endl;
	cout << "container = " << container << endl;
	cout << "ancestor  = " << ancestor << endl;
*/

	for (int32_t i = 0; i < num; ++i) {
		int32_t x = 0;
		int32_t y = 0;

		read_bigendian(is, x);
		read_bigendian(is, y);

		Point p(x * 1.0e-6, y * 1.0e-6);
//		cout << i << "p: { " << 1.0e-6 * x << ", " << 1.0e-6 * y <<" }" << endl;
	}

//	cout << "eof = " << is.eof() << ", tell=" << is.tellg() << endl;
}

}}

/*
int main(int, char** argv)
{
	chart::gshhs::Reader r;
	r.read(argv[1]);
	return 0;
}
*/

