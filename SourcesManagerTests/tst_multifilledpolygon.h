#ifndef TST_MULTIFILLEDPOLYGON_H
#define TST_MULTIFILLEDPOLYGON_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "MultiFilledPolygon.h"

using namespace testing;
using namespace figureTypes;
using namespace std;

struct MultiFilledPolygonFixture : public testing::Test {
  MultiFilledPolygon mlBefore;
  MultiFilledPolygon mlAfter;
  FilledPolygon line1;
  FilledPolygon line2;
  FilledPolygon line3;
  FilledPolygon line4;
  FilledPolygon line5;
  FilledPolygon line6;

  void SetUp() override {
    line1.addCoordinate(Coordinates(3, 1));
    line1.addCoordinate(Coordinates(2, 3));
    line1.addCoordinate(Coordinates(4, 4));
    line2.addCoordinate(Coordinates(6, 2));
    line2.addCoordinate(Coordinates(6, 0));
    line2.addCoordinate(Coordinates(4, 3));
    line3.addCoordinate(Coordinates(3, 2));

    line4.addCoordinate(Coordinates(2.59, 0.53));
    line4.addCoordinate(Coordinates(1.18, 3.35));
    line4.addCoordinate(Coordinates(4, 4.76));
    line5.addCoordinate(Coordinates(6.82, 1.94));
    line5.addCoordinate(Coordinates(6.82, -0.88));
    line5.addCoordinate(Coordinates(4, 3.35));
    line6.addCoordinate(Coordinates(2.59, 1.94));

    mlBefore.addPolygon(line1);
    mlBefore.addPolygon(line2);
    mlBefore.addPolygon(line3);
    mlAfter.addPolygon(line4);
    mlAfter.addPolygon(line5);
    mlAfter.addPolygon(line6);
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

TEST_F(MultiFilledPolygonFixture, TestScalingWhenAreaWill2x) {
  mlBefore.scalingByArea(2, true);
  EXPECT_EQ(mlBefore == mlAfter, true);
  EXPECT_EQ((mlBefore.getScale() - 1.4142) < 0.01, true);
}

TEST_F(MultiFilledPolygonFixture, TestScalingWhithFactor) {
  mlAfter.scalingByFactor(0.707, true);
  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST_F(MultiFilledPolygonFixture, TestScalingWhenAreaWillMinus2x) {
  mlAfter.scalingByArea(0.5, true);
  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST(MultiLineStringTest, TestConstructorsAndTypes) {
  MultiFilledPolygon ml1;
  MultiFilledPolygon ml2("name");
  char *name = new char[10];
  strcpy(name, "NAME");
  MultiFilledPolygon ml3(name);
  delete[] name;

  EXPECT_EQ(ml1.getName(), "");
  EXPECT_EQ(ml2.getName(), "name");
  EXPECT_EQ(ml3.getProperty("NAME"), "name");
  EXPECT_EQ(ml1.getType(), MULTI_FILLED_POLYGON);
  EXPECT_EQ(ml2.getType(), MULTI_FILLED_POLYGON);
  EXPECT_EQ(ml3.getType(), MULTI_FILLED_POLYGON);
}

TEST(MultiLineStringTest, TestEquals) {
  MultiFilledPolygon ml1;
  MultiFilledPolygon ml2;
  FilledPolygon line1;
  FilledPolygon line2;
  FilledPolygon line3;
  FilledPolygon line4;

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
  ml1.addPolygon(line1);
  ml1.addPolygon(line2);
  ml2.addPolygon(line3);
  ml2.addPolygon(line4);

  EXPECT_EQ(ml1 == ml2, true);
}

#endif  // TST_MULTIFILLEDPOLYGON_H
