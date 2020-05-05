#ifndef TST_FILLEDPOLYGON_H
#define TST_FILLEDPOLYGON_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "FilledPolygon.h"

using namespace testing;
using namespace figureTypes;
using namespace std;

struct PolygonFixture : public testing::Test {
  FilledPolygon pBefore;
  FilledPolygon pAfter;
  FilledPolygon pDouble;

  void SetUp() override {
    pBefore.addCoordinate(Coordinates(3, 1));
    pBefore.addCoordinate(Coordinates(2, 3));
    pBefore.addCoordinate(Coordinates(4, 4));
    pBefore.addCoordinate(Coordinates(6, 2));
    pBefore.addCoordinate(Coordinates(6, 0));
    pBefore.addCoordinate(Coordinates(4, 3));
    pBefore.addCoordinate(Coordinates(3, 2));

    pAfter.addCoordinate(Coordinates(2.59, 0.53));
    pAfter.addCoordinate(Coordinates(1.18, 3.35));
    pAfter.addCoordinate(Coordinates(4, 4.76));
    pAfter.addCoordinate(Coordinates(6.82, 1.94));
    pAfter.addCoordinate(Coordinates(6.82, -0.88));
    pAfter.addCoordinate(Coordinates(4, 3.35));
    pAfter.addCoordinate(Coordinates(2.59, 1.94));

    pDouble.addCoordinate(Coordinates(6, 2));
    pDouble.addCoordinate(Coordinates(4, 6));
    pDouble.addCoordinate(Coordinates(8, 8));
    pDouble.addCoordinate(Coordinates(12, 4));
    pDouble.addCoordinate(Coordinates(12, 0));
    pDouble.addCoordinate(Coordinates(8, 6));
    pDouble.addCoordinate(Coordinates(6, 4));
  }

  void TearDown() override {
    pAfter.clear();
    pBefore.clear();
    pDouble.clear();
  }
};

TEST_F(PolygonFixture, TestScalingWhenAreaWill2x) {
  pBefore.scalingByArea(2, true);

  EXPECT_EQ(pBefore == pAfter, true);
}

TEST_F(PolygonFixture, TestScalingWhithFactor) {
  pAfter.scalingByFactor(0.707, true);
  EXPECT_EQ(pBefore == pAfter, true);
  EXPECT_EQ(fabs(pAfter.getScale() - 0.707) <= 0.01, true);
}

TEST_F(PolygonFixture, TestScalingWhenAreaWillMinus2x) {
  pAfter.scalingByArea(0.5, true);
  EXPECT_EQ(pBefore == pAfter, true);
  EXPECT_EQ(fabs(pAfter.getScale() - 0.707) <= 0.01, true);
}

TEST_F(PolygonFixture, TestDoubleScalingWithoutShift) {
  pBefore.scalingByFactor(2, false);
  EXPECT_EQ(pBefore == pDouble, true);
  EXPECT_EQ(pBefore.getScale(), 2);
}

TEST_F(PolygonFixture, TestDoubleScalingWithoutShiftWith4xArea) {
  pBefore.scalingByArea(4, false);
  EXPECT_EQ(pBefore == pDouble, true);
  EXPECT_EQ(pBefore.getScale(), 2);
}

TEST(FilledPolygonTests, TestTypeNameProp) {
  FilledPolygon fp("somename");
  fp.addProperty("prop", "val");

  EXPECT_EQ(fp.getName(), "somename");
  EXPECT_EQ(fp.getProperty("prop"), "val");
  EXPECT_EQ(fp.getType(), FILLED_POLYGON);
}

TEST(FilledPolygonTests, TestGetStartGetEnd) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(1, 2));
  fp.addCoordinate(Coordinates(3, 4));

  EXPECT_EQ(fp.getStart() == Coordinates(1, 2), true);
  EXPECT_EQ(fp.getEnd() == Coordinates(3, 4), true);
  EXPECT_NE(fp.getEnd() == Coordinates(1, 2), true);
  EXPECT_EQ(fp.getType(), FILLED_POLYGON);
}

TEST(FilledPolygonTests, TestOneCoordinate) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(1, 2));

  EXPECT_EQ(fp.getStart() == Coordinates(1, 2), true);
  EXPECT_EQ(fp.getEnd() == Coordinates(1, 2), true);
}

TEST(FilledPolygonTests, TestException) {
  FilledPolygon fp;
  EXPECT_THROW(fp.getStart(), std::logic_error);
  EXPECT_THROW(fp.getEnd(), std::logic_error);
}

TEST(FilledPolygonTests, TestEquals) {
  FilledPolygon fp1("fp1");
  FilledPolygon fp2("fp1");
  FilledPolygon fp3("fp4");
  FilledPolygon fp4("fp4");
  FilledPolygon fp5("fp4");

  fp4.addCoordinate(Coordinates(1, 4));
  fp4.addCoordinate(Coordinates(2, 8));
  fp5.addCoordinate(Coordinates(1, 4));
  fp5.addCoordinate(Coordinates(2, 8));

  EXPECT_EQ(fp1 == fp2, true);
  EXPECT_EQ(fp4 == fp5, true);
  EXPECT_EQ(fp1 == fp3, false);
  EXPECT_EQ(fp1 == fp4, false);
}

#endif  // TST_FILLEDPOLYGON_H
