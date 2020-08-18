#ifndef TST_FILLEDPOLYGON_H
#define TST_FILLEDPOLYGON_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "FilledPolygon.h"

using namespace testing;
using namespace Geometry;
using namespace std;

struct PolygonFixture : public testing::Test {
  FilledPolygon pBefore;
  FilledPolygon pWithShift;
  FilledPolygon pNotShift;

  void SetUp() override {
    pBefore.addObject(Coordinates(2, 2));
    pBefore.addObject(Coordinates(4, 2));
    pBefore.addObject(Coordinates(5, 3));
    pBefore.addObject(Coordinates(3, 4));

    pWithShift.addObject(Coordinates(1.25, 1.625));
    pWithShift.addObject(Coordinates(4.25, 1.625));
    pWithShift.addObject(Coordinates(5.75, 3.125));
    pWithShift.addObject(Coordinates(2.75, 4.625));

    pNotShift.addObject(Coordinates(3, 3));
    pNotShift.addObject(Coordinates(6, 3));
    pNotShift.addObject(Coordinates(7.5, 4.5));
    pNotShift.addObject(Coordinates(4.5, 6));
  }

  void TearDown() override {
    pBefore.clear();
    pWithShift.clear();
    pNotShift.clear();
  }
};

TEST_F(PolygonFixture, Scaling1) {
  pBefore.scalingByFactor(1.5, true);

  EXPECT_TRUE(pBefore == pWithShift);
  EXPECT_FALSE(pBefore == pNotShift);
}

TEST_F(PolygonFixture, Scaling2) {
  pNotShift.scalingByFactor(0.66666, false);

  EXPECT_TRUE(pBefore == pNotShift);
  EXPECT_TRUE(fabs(pNotShift.getScale() - 0.666666) <= 0.01);
}

TEST_F(PolygonFixture, Scaling3) {
  pBefore.scalingByFactor(1.5, false);

  EXPECT_TRUE(pBefore == pNotShift);
  EXPECT_TRUE(fabs(pBefore.getScale() - 1.5) <= 0.01);
}

TEST_F(PolygonFixture, Scaling5) {
  pWithShift.scalingByFactor(0.66666, true);

  EXPECT_TRUE(pBefore == pWithShift);
  EXPECT_EQ(pWithShift.getScale(), 0.66666);
}

TEST_F(PolygonFixture, NotEqual) {
  pWithShift.scalingByFactor(0.66666, true);
  pBefore.addObject(Coordinates(123, 999));

  EXPECT_FALSE(pBefore == pWithShift);
}

TEST(FilledPolygonTests, TestTypeNameProp) {
  FilledPolygon fp("somename");

  fp.addProperty("prop", "val");

  EXPECT_EQ(fp.getName()->compare("somename"), 0);
  EXPECT_EQ(fp.getProperty("prop")->compare("val"), 0);
  EXPECT_EQ(fp.getType(), FILLED_POLYGON);
}

TEST(FilledPolygonTests, TestGetStartGetEnd) {
  FilledPolygon fp;

  fp.addObject(Coordinates(1, 2));
  fp.addObject(Coordinates(3, 4));

  EXPECT_TRUE(**fp.cbegin() == Coordinates(1, 2));
  EXPECT_TRUE(**(fp.cend() - 1) == Coordinates(3, 4));
  EXPECT_EQ(fp.getType(), FILLED_POLYGON);
}

TEST(FilledPolygonTests, TestOneCoordinate) {
  FilledPolygon fp;

  fp.addObject(Coordinates(1, 2));

  EXPECT_TRUE(**fp.cbegin() == Coordinates(1, 2));
  EXPECT_TRUE(**(fp.cend() - 1) == Coordinates(1, 2));
}

TEST(FilledPolygonTests, TestEquals) {
  FilledPolygon fp1("fp1");
  FilledPolygon fp2("fp1");
  FilledPolygon fp3("fp4");
  FilledPolygon fp4("fp4");
  FilledPolygon fp5("fp4");
  FilledPolygon fp6("fp6");
  FilledPolygon fp7("fp7");

  fp4.addObject(Coordinates(1, 4));
  fp4.addObject(Coordinates(2, 8));
  fp5.addObject(Coordinates(1, 4));
  fp5.addObject(Coordinates(2, 8));

  EXPECT_TRUE(fp1 == fp2);
  EXPECT_TRUE(fp4 == fp5);
  EXPECT_FALSE(fp1 == fp3);
  EXPECT_FALSE(fp1 == fp4);
  EXPECT_FALSE(fp7 == fp6);
}

TEST_F(PolygonFixture, TestIsInPolygon) {
  Coordinates c1(2, 2);
  Coordinates c2(4, 2);
  Coordinates c3(5, 3);
  Coordinates c4(3, 4);
  Coordinates c5(5, 0.5);
  Coordinates c6(1, 2);
  Coordinates c7(4, 1.5);

  EXPECT_TRUE(pBefore.isContains(c1));
  EXPECT_TRUE(pBefore.isContains(c2));
  EXPECT_TRUE(pBefore.isContains(c3));
  EXPECT_TRUE(pBefore.isContains(c4));
  EXPECT_FALSE(pBefore.isContains(c5));
  EXPECT_FALSE(pBefore.isContains(c6));
  EXPECT_FALSE(pBefore.isContains(c7));
}

#endif  // TST_FILLEDPOLYGON_H
