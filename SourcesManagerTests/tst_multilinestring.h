#ifndef TST_MULTILINESTRING_H
#define TST_MULTILINESTRING_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "MultiLineString.h"
#include "ParsersAll.h"

using namespace testing;
using namespace Geometry;
using namespace std;

struct MultiLineFixture : public testing::Test {
  MultiLineString mlBefore;
  MultiLineString mlAfter;
  LineString line1;
  LineString line2;

  LineString line3;
  LineString line4;

  void SetUp() override {
    line1.addObject(Coordinates(2, 2));
    line1.addObject(Coordinates(4, 2));
    line1.addObject(Coordinates(5, 3));
    line2.addObject(Coordinates(3, 4));

    line3.addObject(Coordinates(1.25, 1.625));
    line3.addObject(Coordinates(4.25, 1.625));
    line3.addObject(Coordinates(5.75, 3.125));
    line4.addObject(Coordinates(2.75, 4.625));

    mlBefore.addObject(line1);
    mlBefore.addObject(line2);

    mlAfter.addObject(line3);
    mlAfter.addObject(line4);
  }

  void TearDown() override {
    line1.clear();
    line2.clear();
    line3.clear();
    line4.clear();

    mlAfter.clear();
    mlBefore.clear();
  }
};

TEST_F(MultiLineFixture, countObjects) {
  EXPECT_EQ(mlBefore.countObjs(), 4);
  EXPECT_EQ(mlAfter.countObjs(), 4);
}

TEST_F(MultiLineFixture, Scaling1) {
  mlBefore.scalingByFactor(1.5, true);

  EXPECT_EQ(mlBefore == mlAfter, true);
  EXPECT_EQ((mlBefore.getScale() - 1.5) < 0.01, true);
}

TEST_F(MultiLineFixture, Scaling2) {
  mlAfter.scalingByFactor(0.666666, true);

  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST_F(MultiLineFixture, Scaling3) {
  mlAfter.scalingByFactor(2, false);
  mlAfter.scalingByFactor(1 / 2.0, false);
  mlBefore.scalingByFactor(1.5, true);

  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST_F(MultiLineFixture, Scaling4) {
  mlAfter.scalingByFactor(2, true);
  mlAfter.scalingByFactor(1 / 2.0, true);
  mlBefore.scalingByFactor(1.5, true);

  EXPECT_EQ(mlBefore == mlAfter, true);
}

TEST(MultiLineStringTest, TestConstructorsAndTypes) {
  MultiLineString ml1;
  MultiLineString ml2("nAmE");

  EXPECT_EQ(ml1.getName(), nullptr);
  EXPECT_EQ(ml2.getName()->compare("name"), 0);
  EXPECT_EQ(ml2.getProperty("NAME")->compare("name"), 0);
  EXPECT_EQ(ml1.getType(), MULTI_LINE_STR);
  EXPECT_EQ(ml2.getType(), MULTI_LINE_STR);
}

TEST(MultiLineStringTest, TestEquals) {
  MultiLineString ml1;
  MultiLineString ml2;
  MultiLineString ml3;
  LineString line1;
  LineString line2;
  LineString line3;
  LineString line4;

  line1.addObject(Coordinates(3, 1));
  line2.addObject(Coordinates(2, 3));
  line1.addObject(Coordinates(4, 4));
  line2.addObject(Coordinates(6, 2));
  line2.addObject(Coordinates(6, 0));
  line3.addObject(Coordinates(3, 1));
  line4.addObject(Coordinates(2, 3));
  line3.addObject(Coordinates(4, 4));
  line4.addObject(Coordinates(6, 2));
  line4.addObject(Coordinates(6, 0));
  ml1.addObject(line1);
  ml1.addObject(line2);
  ml2.addObject(line3);
  ml2.addObject(line4);
  ml3 = ml2;
  ml2.addObject(LineString());

  EXPECT_TRUE(ml1 == ml3);
  EXPECT_FALSE(ml1 == ml2);
}

/*#include "ParsersAll.h"
 TEST_F(MultiLineFixture, TestSerializeAndDesirealize) {
 mlBefore.scalingByArea(2, true);

 EXPECT_EQ(mpBefore == mpAfter, true);

  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  mlToJSON(mlBefore, writer);
  MultiLineString multLine = jsonToML(sb.GetString());

  EXPECT_EQ(mlBefore == multLine, true);
}

TEST_F(MultiLineFixture, TestSerializeAndDesirealize2) {
  mlBefore.scalingByArea(2, true);

  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  mlToJSON(mlBefore, writer);
  MultiLineString multLine = jsonToML(sb.GetString());

  EXPECT_EQ(mlBefore == mlAfter, true);
}*/

#endif  // TST_MULTILINESTRING_H
