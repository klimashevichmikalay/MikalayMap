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

  EXPECT_EQ(pBefore == pWithShift, true);
  EXPECT_EQ(pBefore == pNotShift, false);
}

TEST_F(PolygonFixture, Scaling2) {
  pNotShift.scalingByFactor(0.66666, false);
  EXPECT_EQ(pBefore == pNotShift, true);
  EXPECT_EQ(fabs(pNotShift.getScale() - 0.666666) <= 0.01, true);
}

TEST_F(PolygonFixture, Scaling3) {
  pBefore.scalingByFactor(1.5, false);
  EXPECT_EQ(pBefore == pNotShift, true);
  EXPECT_EQ(fabs(pBefore.getScale() - 1.5) <= 0.01, true);
}

TEST_F(PolygonFixture, Scaling5) {
  pWithShift.scalingByFactor(0.66666, true);
  EXPECT_EQ(pBefore == pWithShift, true);
  EXPECT_EQ(pWithShift.getScale(), 0.66666);
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

  EXPECT_EQ(**fp.cbegin() == Coordinates(1, 2), true);
  EXPECT_EQ(**(fp.cend() - 1) == Coordinates(3, 4), true);
  EXPECT_EQ(fp.getType(), FILLED_POLYGON);
}

TEST(FilledPolygonTests, TestOneCoordinate) {
  FilledPolygon fp;
  fp.addObject(Coordinates(1, 2));

  EXPECT_EQ(**fp.cbegin() == Coordinates(1, 2), true);
  EXPECT_EQ(**(fp.cend() - 1) == Coordinates(1, 2), true);
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

  EXPECT_EQ(fp1 == fp2, true);
  EXPECT_EQ(fp4 == fp5, true);
  EXPECT_EQ(fp1 == fp3, false);
  EXPECT_EQ(fp1 == fp4, false);
  EXPECT_EQ(fp7 == fp6, false);
}

TEST_F(PolygonFixture, TestIsInPolygon) {
  Coordinates c1(2, 2);    // t
  Coordinates c2(4, 2);    // t
  Coordinates c3(5, 3);    // t
  Coordinates c4(3, 4);    // f
  Coordinates c5(5, 0.5);  // f
  Coordinates c6(1, 2);    // f
  Coordinates c7(4, 1.5);  // f

  EXPECT_EQ(pBefore.isContains(c1), true);
  EXPECT_EQ(pBefore.isContains(c2), true);
  EXPECT_EQ(pBefore.isContains(c3), true);
  EXPECT_EQ(pBefore.isContains(c4), true);
  EXPECT_EQ(pBefore.isContains(c5), false);
  EXPECT_EQ(pBefore.isContains(c6), false);
  EXPECT_EQ(pBefore.isContains(c7), false);
}

/*
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
*/

#endif  // TST_FILLEDPOLYGON_H
