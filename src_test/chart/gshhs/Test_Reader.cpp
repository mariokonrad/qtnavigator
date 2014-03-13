#include <chart/gshhs/Reader.hpp>
#include <chart/gshhs/Chart.hpp>
#include <gtest/global.hpp>
#include <gtest/gtest.h>

namespace {

class Test_chart_gshhs_Reader : public ::testing::Test {};

TEST_F(Test_chart_gshhs_Reader, read_crude_chart_from_file)
{
	chart::gshhs::Reader reader;
	chart::gshhs::Chart chart;
	reader.read(testing::global::data_root() + "/gshhs/gshhs_c.b", chart);

	EXPECT_EQ(1782u, chart.num_polygons());
}

}
