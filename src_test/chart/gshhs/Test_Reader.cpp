#include <chart/gshhs/Reader.hpp>
#include <gtest/gtest.h>

namespace {

class Test_chart_gshhs_Reader : public ::testing::Test {};

TEST_F(Test_chart_gshhs_Reader, not_really_a_unittest)
{
	// TODO: path to data must be specified at comamnd line

	chart::gshhs::Reader reader;
	reader.read("data/gshhs/gshhs_c.b");
}

}
