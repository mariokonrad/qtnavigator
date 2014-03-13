#include <chart/gshhs/Reader.hpp>
#include <gtest/global.hpp>
#include <gtest/gtest.h>

namespace {

class Test_chart_gshhs_Reader : public ::testing::Test {};

TEST_F(Test_chart_gshhs_Reader, not_really_a_unittest)
{
	chart::gshhs::Reader reader;
	reader.read(testing::global::data_root() + "/gshhs/gshhs_c.b");
}

}
