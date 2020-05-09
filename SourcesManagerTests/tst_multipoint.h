#ifndef TST_MULTIPOINT_H
#define TST_MULTIPOINT_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "MultiPoint.h"
#include "ParsersAll.h"

using namespace testing;
using namespace figureTypes;
using namespace std;

struct MultiPointFixture : public testing::Test {
  MultiPoint mpBefore;
  MultiPoint mpAfter;

  void SetUp() override {
    mpBefore.addPoint(Coordinates(3, 1));
    mpBefore.addPoint(Coordinates(2, 3));
    mpBefore.addPoint(Coordinates(4, 4));
    mpBefore.addPoint(Coordinates(6, 2));
    mpBefore.addPoint(Coordinates(6, 0));
    mpBefore.addPoint(Coordinates(4, 3));
    mpBefore.addPoint(Coordinates(3, 2));

    mpAfter.addPoint(Coordinates(2.58579, 0.526613));
    mpAfter.addPoint(Coordinates(1.17157, 3.35504));
    mpAfter.addPoint(Coordinates(4, 4.76925));
    mpAfter.addPoint(Coordinates(6.82843, 1.94083));
    mpAfter.addPoint(Coordinates(6.82843, -0.887601));
    mpAfter.addPoint(Coordinates(4, 3.355039));
    mpAfter.addPoint(Coordinates(2.58579, 1.94083));
  }

  void TearDown() override {
    mpAfter.clear();
    mpBefore.clear();
  }
};

TEST_F(MultiPointFixture, TestScalingWhenAreaWill2x) {
  mpBefore.scalingByArea(2, true);

  EXPECT_EQ(mpBefore == mpAfter, true);
  EXPECT_EQ((mpBefore.getScale() - 1.4142) < 0.01, true);
}

TEST_F(MultiPointFixture, TestScalingWhithFactor) {
  mpAfter.scalingByFactor(0.707106, true);

  EXPECT_EQ(mpBefore == mpAfter, true);
  EXPECT_EQ((mpAfter.getScale() - 0.707106) <= 0.01, true);
}

TEST(MultiPointTests, TestConstructors) {
  MultiPoint mp1;
  MultiPoint mp2("name2");

  char *name = new char[20];
  strcpy(name, "name3");

  MultiPoint mp3(name);
  delete[] name;

  EXPECT_EQ(mp1.getName(), "");
  EXPECT_EQ(mp2.getName(), "name2");
  EXPECT_EQ(mp3.getName(), "name3");
  EXPECT_EQ(mp3.getType(), MULTI_POINT);
  EXPECT_EQ(mp2.getType(), MULTI_POINT);
  EXPECT_EQ(mp1.getType(), MULTI_POINT);
  EXPECT_EQ(mp3.getProperty("NAME"), "name3");
}

TEST(MultiPointTests, TestEquals) {
  MultiPoint mp1;
  MultiPoint mp2;
  MultiPoint mp3("name");
  MultiPoint mp4("name");
  MultiPoint mp5("name");
  MultiPoint mp6("ngrbgrrame");
  MultiPoint mp7("nggregrbgrrame");

  Point p1("p");
  Point p2("p");

  mp1.addPoint(p1);
  mp1.addPoint(p2);
  mp2.addPoint(p1);
  mp2.addPoint(p2);

  mp3.addPoint(p1);
  mp4.addPoint(p2);
  mp4.addPoint(p1);
  mp3.addPoint(p2);

  mp5.addPoint(p1);
  p2.setX(111);
  mp5.addPoint(p2);

  EXPECT_EQ(mp1 == mp2, true);
  EXPECT_EQ(mp3 == mp4, true);
  EXPECT_EQ(mp1 == mp4, false);
  EXPECT_EQ(mp6 == mp7, false);
  EXPECT_EQ(mp4 == mp5, false);
  EXPECT_EQ(mp4.getPoints().size(), 2);
  EXPECT_EQ(mp5.isContains(p2), true);
  EXPECT_EQ(mp5.isContains(p1), true);
  EXPECT_EQ(mp4.isContains(p2), false);

  mp4.clear();
  EXPECT_EQ(mp4.getPoints().size(), 0);
}

//#include "ParsersAll.h"
TEST_F(MultiPointFixture, TestSerializeAndDesirealize) {
  /*mpBefore.scalingByArea(2, true);

    EXPECT_EQ(mpBefore == mpAfter, true);*/

  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  mpToJSON(mpBefore, writer);
  MultiPoint mPointAfter = jsonToMP(sb.GetString());

  EXPECT_EQ(mpBefore == mPointAfter, true);
}

TEST_F(MultiPointFixture, TestSerializeAndDesirealize2) {
  mpBefore.scalingByArea(2, true);

  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  mpToJSON(mpBefore, writer);
  MultiPoint mp2 = jsonToMP(sb.GetString());
  EXPECT_EQ(mp2 == mpAfter, true);
}

#endif  // TST_MULTIPOINT_H
