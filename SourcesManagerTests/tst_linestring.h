#ifndef TST_LINESTRING_H
#define TST_LINESTRING_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <vector>

#include "LineString.h"

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

    lsAfter.addCoordinate(Coordinates(2.59, 0.53));
    lsAfter.addCoordinate(Coordinates(1.18, 3.35));
    lsAfter.addCoordinate(Coordinates(4, 4.76));
    lsAfter.addCoordinate(Coordinates(6.82, 1.94));
    lsAfter.addCoordinate(Coordinates(6.82, -0.88));
    lsAfter.addCoordinate(Coordinates(4, 3.35));
    lsAfter.addCoordinate(Coordinates(2.59, 1.94));
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
  lsAfter.scalingByFactor(0.707, true);
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

#endif  // TST_LINESTRING_H
