#ifndef TST_CORE_H
#define TST_CORE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Core.h"
#include "ParsersCommand.h"
#include "SSConstants.h"

using namespace testing;
/*
struct Core0Fixture : public testing::Test {
  void SetUp() override {
    vector<Point> v;
    for (int i = 0; i < 100; i++) v.push_back(Point(Coordinates(i, i)));

    ParsersCommand pc;
    pc.getParser(JSON)->savePoints(v, "testdem");
  }

  void TearDown() override {}
};

TEST_F(Core0Fixture, TestGetDEM) {
  Core core;
  core.setDEM("testdem", 20);
  vector<vector<Point>> dem = core.getDEM();

  EXPECT_EQ(dem.size(), 5);
  EXPECT_EQ(dem[0].size(), 20);
  EXPECT_EQ(dem[1].size(), 20);
  EXPECT_EQ(dem[2].size(), 20);
  EXPECT_EQ(dem[3].size(), 20);
  EXPECT_EQ(dem[4].size(), 20);
}

struct Core1Fixture : public testing::Test {
  void SetUp() override {
    FilledPolygon lake1;
    FilledPolygon lake2;
    FilledPolygon bad1;
    FilledPolygon swamp1;

    lake1.addCoordinate(Coordinates(550, 950));
    lake1.addCoordinate(Coordinates(250, 950));
    lake1.addCoordinate(Coordinates(250, 1300));
    lake1.addCoordinate(Coordinates(550, 1300));

    lake2.addCoordinate(Coordinates(400, 200));
    lake2.addCoordinate(Coordinates(200, 400));
    lake2.addCoordinate(Coordinates(300, 500));
    lake2.addCoordinate(Coordinates(450, 500));
    lake2.addCoordinate(Coordinates(550, 350));

    bad1.addCoordinate(Coordinates(600, 600));
    bad1.addCoordinate(Coordinates(250, 600));
    bad1.addCoordinate(Coordinates(250, 850));
    bad1.addCoordinate(Coordinates(600, 850));

    swamp1.addCoordinate(Coordinates(1250, 600));
    swamp1.addCoordinate(Coordinates(800, 600));
    swamp1.addCoordinate(Coordinates(800, 300));

    vector<FilledPolygon> lakesVector;
    vector<FilledPolygon> badsVector;
    vector<FilledPolygon> swampsVector;

    lakesVector.push_back(lake1);
    lakesVector.push_back(lake2);

    badsVector.push_back(bad1);

    swampsVector.push_back(swamp1);

    ParsersCommand pc;

    pc.getParser(JSON)->saveFilledPolygons(lakesVector, "testLakes");
    pc.getParser(JSON)->saveFilledPolygons(badsVector, "testBads");
    pc.getParser(JSON)->saveFilledPolygons(swampsVector, "testSwamps");
  }

  void TearDown() override {}
};

TEST_F(Core1Fixture, TestCore) {
  Core core("testSwamps", "testLakes", "testBads");
  Point p1(Coordinates(200, 1200));   // f
  Point p2(Coordinates(400, 900));    // f
  Point p3(Coordinates(300, 550));    // f
  Point p4(Coordinates(1000, 1000));  // f
  Point p5(Coordinates(1100, 300));   // f

  Point p6(Coordinates(400, 1200));  // t
  Point p7(Coordinates(500, 700));   // t
  Point p8(Coordinates(400, 250));   // t
  Point p9(Coordinates(900, 400));   // t
  Point p10(Coordinates(350, 450));  // t

  EXPECT_EQ(core.isBadPoint(p1), false);
  EXPECT_EQ(core.isBadPoint(p2), false);
  EXPECT_EQ(core.isBadPoint(p3), false);
  EXPECT_EQ(core.isBadPoint(p4), false);
  EXPECT_EQ(core.isBadPoint(p5), false);

  EXPECT_EQ(core.isBadPoint(p6), true);
  EXPECT_EQ(core.isBadPoint(p7), true);
  EXPECT_EQ(core.isBadPoint(p8), true);
  EXPECT_EQ(core.isBadPoint(p9), true);
  EXPECT_EQ(core.isBadPoint(p10), true);
}
*/
#endif  // TST_CORE_H
