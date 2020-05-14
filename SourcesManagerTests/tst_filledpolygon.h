#ifndef TST_FILLEDPOLYGON_H
#define TST_FILLEDPOLYGON_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "FilledPolygon.h"
#include "ParsersAll.h"

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

    pAfter.addCoordinate(Coordinates(2.58579, 0.526613));
    pAfter.addCoordinate(Coordinates(1.17157, 3.35504));
    pAfter.addCoordinate(Coordinates(4, 4.76925));
    pAfter.addCoordinate(Coordinates(6.82843, 1.94083));
    pAfter.addCoordinate(Coordinates(6.82843, -0.887601));
    pAfter.addCoordinate(Coordinates(4, 3.355039));
    pAfter.addCoordinate(Coordinates(2.58579, 1.94083));

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
  pAfter.scalingByFactor(0.707106, true);
  EXPECT_EQ(pBefore == pAfter, true);
  EXPECT_EQ(fabs(pAfter.getScale() - 0.707106) <= 0.01, true);
}

TEST_F(PolygonFixture, TestScalingWhenAreaWillMinus2x) {
  pAfter.scalingByArea(0.5, true);
  EXPECT_EQ(pBefore == pAfter, true);
  EXPECT_EQ(fabs(pAfter.getScale() - 0.707106) <= 0.01, true);
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
  FilledPolygon fp6("fp6");
  FilledPolygon fp7("fp7");
  fp4.addCoordinate(Coordinates(1, 4));
  fp4.addCoordinate(Coordinates(2, 8));
  fp5.addCoordinate(Coordinates(1, 4));
  fp5.addCoordinate(Coordinates(2, 8));

  EXPECT_EQ(fp1 == fp2, true);
  EXPECT_EQ(fp4 == fp5, true);
  EXPECT_EQ(fp1 == fp3, false);
  EXPECT_EQ(fp1 == fp4, false);
  EXPECT_EQ(fp7 == fp6, false);
}

TEST_F(PolygonFixture, TestSerializeAndDesirealize) {
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  fpToJSON(pBefore, writer);
  FilledPolygon polig = jsonToFP(sb.GetString());

  EXPECT_EQ(pBefore == polig, true);
}

TEST_F(PolygonFixture, TestSerializeAndDesirealize2) {
  pBefore.scalingByArea(2, true);
  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  fpToJSON(pBefore, writer);
  FilledPolygon fpolig = jsonToFP(sb.GetString());

  EXPECT_EQ(fpolig == pAfter, true);
}

TEST_F(PolygonFixture, TestIsInPolygon) {
  Coordinates c1(2.75, 2);  // t
  Coordinates c2(4, 3.5);   // t
  Coordinates c3(5, 2.5);   // t
  Coordinates c4(6, 3.5);   // f
  Coordinates c5(5, 0.5);   // f
  Coordinates c6(1, 2);     // f
  Coordinates c7(4, 1.5);   // f

  EXPECT_EQ(pBefore.isInPolygon(c1), true);
  EXPECT_EQ(pBefore.isInPolygon(c2), true);
  EXPECT_EQ(pBefore.isInPolygon(c3), true);
  EXPECT_EQ(pBefore.isInPolygon(c4), false);
  EXPECT_EQ(pBefore.isInPolygon(c5), false);
  EXPECT_EQ(pBefore.isInPolygon(c6), false);
  EXPECT_EQ(pBefore.isInPolygon(c7), false);
}
#endif  // TST_FILLEDPOLYGON_H
