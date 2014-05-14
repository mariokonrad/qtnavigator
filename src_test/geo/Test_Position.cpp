#include <geo/Position.hpp>
#include <gtest/gtest.h>

namespace {

class Test_geo_Position : public ::testing::Test {};

TEST_F(Test_geo_Position, construction_default)
{
	geo::Position p;

	EXPECT_EQ(0.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
}

TEST_F(Test_geo_Position, construction_explicit)
{
	geo::Position p{1.0, 2.0};

	EXPECT_EQ(1.0, p.lat());
	EXPECT_EQ(2.0, p.lon());
}

TEST_F(Test_geo_Position, construction_explicit_large)
{
	geo::Position p{95.0, 200.0};

	EXPECT_EQ(95.0, p.lat());
	EXPECT_EQ(200.0, p.lon());
}

TEST_F(Test_geo_Position, normalize_latitude_positive)
{
	{
	geo::Position p = geo::Position{0.0, 0.0}.normalize();
	EXPECT_EQ(0.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{1.0, 0.0}.normalize();
	EXPECT_EQ(1.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{30.0, 0.0}.normalize();
	EXPECT_EQ(30.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{60.0, 0.0}.normalize();
	EXPECT_EQ(60.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{89.0, 0.0}.normalize();
	EXPECT_EQ(89.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{90.0, 0.0}.normalize();
	EXPECT_EQ(90.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{91.0, 0.0}.normalize();
	EXPECT_EQ(-89.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{180.0, 0.0}.normalize();
	EXPECT_EQ(0.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{270.0, 0.0}.normalize();
	EXPECT_EQ(90.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}
}

TEST_F(Test_geo_Position, normalize_latitude_negative)
{
	{
	geo::Position p = geo::Position{-0.0, 0.0}.normalize();
	EXPECT_EQ(0.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-1.0, 0.0}.normalize();
	EXPECT_EQ(-1.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-30.0, 0.0}.normalize();
	EXPECT_EQ(-30.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-60.0, 0.0}.normalize();
	EXPECT_EQ(-60.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-89.0, 0.0}.normalize();
	EXPECT_EQ(-89.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-90.0, 0.0}.normalize();
	EXPECT_EQ(-90.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-91.0, 0.0}.normalize();
	EXPECT_EQ(89.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-180.0, 0.0}.normalize();
	EXPECT_EQ(0.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}

	{
	geo::Position p = geo::Position{-270.0, 0.0}.normalize();
	EXPECT_EQ(-90.0, p.lat());
	EXPECT_EQ(0.0, p.lon());
	}
}

}
