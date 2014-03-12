#ifndef __CHART__GSHHS__READER__HPP__
#define __CHART__GSHHS__READER__HPP__

#include <string>
#include <istream>
#include <stdint.h>

namespace chart {
namespace gshhs {

/// Reads GSHHS (binary) files.
class Reader
{
public:
	void read(std::string path);

private:
	void read_bigendian(std::istream& is, int32_t& data);
	void read_polygon(std::istream& is);
};

}}

#endif
