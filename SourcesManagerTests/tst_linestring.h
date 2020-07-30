#ifndef TST_LINESTRING_H
#define TST_LINESTRING_H
/*
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

#include "LineString.h"
#include "ParsersAll.h"

using namespace testing;
using namespace figureTypes;

struct LineFixture : public testing::Test {
  LineString lsBefore;
  LineString lsAfter;

  void SetUp() override {
    lsBefore.addCoordinate(Coordinates(3, 1));
    lsBefore.addCoordinate(Coordinates(2, 3));
    lsBefore.addCoordinate(Coordinates(4, 4));
    lsBefore.addCoordinate(Coordinates(6, 2));
    lsBefore.addCoordinate(Coordinates(6, 0));
    lsBefore.addCoordinate(Coordinates(4, 3));
    lsBefore.addCoordinate(Coordinates(3, 2));

    lsAfter.addCoordinate(Coordinates(2.58579, 0.526613));
    lsAfter.addCoordinate(Coordinates(1.17157, 3.35504));
    lsAfter.addCoordinate(Coordinates(4, 4.76925));
    lsAfter.addCoordinate(Coordinates(6.82843, 1.94083));
    lsAfter.addCoordinate(Coordinates(6.82843, -0.887601));
    lsAfter.addCoordinate(Coordinates(4, 3.355039));
    lsAfter.addCoordinate(Coordinates(2.58579, 1.94083));
  }

  void TearDown() override {
    lsAfter.clear();
    lsBefore.clear();
  }
};

TEST_F(LineFixture, TestScalingWhenAreaWill2x) {
  lsBefore.scalingByArea(2, true);

  EXPECT_EQ(lsBefore == lsAfter, true);
}

TEST_F(LineFixture, TestScalingWhithFactor) {
  lsAfter.scalingByFactor(0.707106, true);
  EXPECT_EQ(lsBefore == lsAfter, true);
}

TEST_F(LineFixture, TestScalingWhenAreaWillMinus2x) {
  lsAfter.scalingByArea(0.5, true);
  EXPECT_EQ(lsBefore == lsAfter, true);
}

TEST(LineTests, TestLineSetGet) {
  LineString ls("HELLO");
  ls.addProperty("pROp", "val");
  EXPECT_EQ(ls.getName(), "hello");
  EXPECT_EQ(ls.getProperty("prop"), "val");
  EXPECT_EQ(ls.getProperty("name"), "hello");
  EXPECT_EQ(ls.getType(), LINE_STR);
}

//#include "ParsersAll.h"
TEST_F(LineFixture, TestSerializeAndDesirealize) {
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  lineToJSON(lsBefore, writer);
  LineString line = jsonToLine(sb.GetString());

  EXPECT_EQ(lsBefore == line, true);
}

TEST_F(LineFixture, TestSerializeAndDesirealize2) {
  lsBefore.scalingByArea(2, true);
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  lineToJSON(lsBefore, writer);
  LineString line = jsonToLine(sb.GetString());

  EXPECT_EQ(line == lsAfter, true);
}

TEST_F(LineFixture, TestIsContains) {
  EXPECT_EQ(lsBefore.isContains(Coordinates(3, 1)), true);
  EXPECT_EQ(lsBefore.isContains(Coordinates(2, 3)), true);
  EXPECT_EQ(lsBefore.isContains(Coordinates(4, 4)), true);
  EXPECT_EQ(lsBefore.isContains(Coordinates(6, 2)), true);
  EXPECT_EQ(lsBefore.isContains(Coordinates(6, 0)), true);
  EXPECT_EQ(lsBefore.isContains(Coordinates(4, 3)), true);
  EXPECT_EQ(lsBefore.isContains(Coordinates(3, 2)), true);

  EXPECT_EQ(lsBefore.isContains(Coordinates(5, 5)), false);
  EXPECT_EQ(lsBefore.isContains(Coordinates(6, 3)), false);
  EXPECT_EQ(lsBefore.isContains(Coordinates(10, 10)), false);
}
*/
#endif  // TST_LINESTRING_H
