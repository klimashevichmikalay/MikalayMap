#ifndef TST_LINESTRING_H
#define TST_LINESTRING_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

#include "LineString.h"
#include "ParsersAll.h"

using namespace testing;
using namespace Geometry;

struct LineFixture : public testing::Test {
  LineString lsBefore;
  LineString lsAfter;

  void SetUp() override {
    lsBefore.addObject(Coordinates(3, 1));
    lsBefore.addObject(Coordinates(2, 3));
    lsBefore.addObject(Coordinates(4, 4));
    lsBefore.addObject(Coordinates(6, 2));
    lsBefore.addObject(Coordinates(6, 0));
    lsBefore.addObject(Coordinates(4, 3));
    lsBefore.addObject(Coordinates(3, 2));

    lsAfter.addObject(Coordinates(2.58579, 0.526613));
    lsAfter.addObject(Coordinates(1.17157, 3.35504));
    lsAfter.addObject(Coordinates(4, 4.76925));
    lsAfter.addObject(Coordinates(6.82843, 1.94083));
    lsAfter.addObject(Coordinates(6.82843, -0.887601));
    lsAfter.addObject(Coordinates(4, 3.355039));
    lsAfter.addObject(Coordinates(2.58579, 1.94083));
  }

  void TearDown() override {
    lsAfter.clear();
    lsBefore.clear();
  }
};

TEST_F(LineFixture, Scaling1) {
  lsBefore.scalingByFactor(0.707106, false);
  EXPECT_EQ(lsBefore == lsAfter, false);
}

TEST_F(LineFixture, Scaling2) {
  lsAfter.scalingByFactor(1.160187, false);
  EXPECT_EQ(lsBefore == lsAfter, false);
}

TEST_F(LineFixture, Scaling3) {
  lsAfter.scalingByFactor(sqrt(2.0), true);
  EXPECT_EQ(lsBefore == lsAfter, false);
}

TEST(LineTests, LineSetGet) {
  LineString ls("HELLO");
  ls.addProperty("pROp", "val");
  EXPECT_EQ(ls.getName()->compare("hello"), 0);
  EXPECT_EQ(ls.getProperty("prop")->compare("val"), 0);
  EXPECT_EQ(ls.getProperty("name")->compare("hello"), 0);
  EXPECT_EQ(ls.getProperty("namegrt"), nullptr);
  EXPECT_EQ(ls.getType(), LINE_STR);
}

TEST_F(LineFixture, IsContains) {
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

//#include "ParsersAll.h"
/*TEST_F(LineFixture, TestSerializeAndDesirealize) {
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
*/
#endif  // TST_LINESTRING_H
