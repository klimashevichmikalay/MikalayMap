#ifndef TST_MULTILINESTRING_H
#define TST_MULTILINESTRING_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "MultiLineString.h"

using namespace testing;
using namespace figureTypes;
using namespace std;

struct MultiLineFixture : public testing::Test {
  MultiLineString mlBefore;
  MultiLineString mlAfter;
  LineString line1;
  LineString line2;
  LineString line3;
  LineString line4;
  LineString line5;
  LineString line6;

  void SetUp() override {
    line1.addCoordinate(Coordinates(3, 1));
    line1.addCoordinate(Coordinates(2, 3));
    line1.addCoordinate(Coordinates(4, 4));
    line2.addCoordinate(Coordinates(6, 2));
    line2.addCoordinate(Coordinates(6, 0));
    line2.addCoordinate(Coordinates(4, 3));
    line3.addCoordinate(Coordinates(3, 2));

    line4.addCoordinate(Coordinates(2.58579, 0.526613));
    line4.addCoordinate(Coordinates(1.17157, 3.35504));
    line4.addCoordinate(Coordinates(4, 4.76925));
    line5.addCoordinate(Coordinates(6.82843, 1.94083));
    line5.addCoordinate(Coordinates(6.82843, -0.887601));
    line5.addCoordinate(Coordinates(4, 3.355039));
    line6.addCoordinate(Coordinates(2.58579, 1.94083));

    mlBefore.addLine(line1);
    mlBefore.addLine(line2);
    mlBefore.addLine(line3);
    mlAfter.addLine(line4);
    mlAfter.addLine(line5);
    mlAfter.addLine(line6);
  }

  void TearDown() override {
    mlAfter.clear();
    mlBefore.clear();
    line1.clear();
    line2.clear();
    line3.clear();
    line4.clear();
    line5.clear();
    line6.clear();
  }
};

TEST_F(MultiLineFixture, TestScalingWhenAreaWill2x) {
  mlBefore.scalingByArea(2, true);
  EXPECT_EQ(mlBefore == mlAfter, true);
  EXPECT_EQ((mlBefore.getScale() - 1.4142) < 0.01, true);
}

TEST_F(MultiLineFixture, TestScalingWhithFactor) {
  mlAfter.scalingByFactor(0.707106, true);
  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST_F(MultiLineFixture, TestScalingWhenAreaWillMinus2x) {
  mlAfter.scalingByArea(0.5, true);
  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST(MultiLineStringTest, TestConstructorsAndTypes) {
  MultiLineString ml1;
  MultiLineString ml2("name");
  char *name = new char[10];
  strcpy(name, "NAME");
  MultiLineString ml3(name);
  delete[] name;

  EXPECT_EQ(ml1.getName(), "");
  EXPECT_EQ(ml2.getName(), "name");
  EXPECT_EQ(ml3.getProperty("NAME"), "name");
  EXPECT_EQ(ml1.getType(), MULTI_LINE_STR);
  EXPECT_EQ(ml2.getType(), MULTI_LINE_STR);
  EXPECT_EQ(ml3.getType(), MULTI_LINE_STR);
}

TEST(MultiLineStringTest, TestEquals) {
  MultiLineString ml1;
  MultiLineString ml2;
  LineString line1;
  LineString line2;
  LineString line3;
  LineString line4;

  line1.addCoordinate(Coordinates(3, 1));
  line2.addCoordinate(Coordinates(2, 3));
  line1.addCoordinate(Coordinates(4, 4));
  line2.addCoordinate(Coordinates(6, 2));
  line2.addCoordinate(Coordinates(6, 0));
  line3.addCoordinate(Coordinates(3, 1));
  line4.addCoordinate(Coordinates(2, 3));
  line3.addCoordinate(Coordinates(4, 4));
  line4.addCoordinate(Coordinates(6, 2));
  line4.addCoordinate(Coordinates(6, 0));
  ml1.addLine(line1);
  ml1.addLine(line2);
  ml2.addLine(line3);
  ml2.addLine(line4);

  EXPECT_EQ(ml1 == ml2, true);
}

#endif  // TST_MULTILINESTRING_H
