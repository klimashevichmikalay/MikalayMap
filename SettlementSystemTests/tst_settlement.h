#ifndef TST_SETTLEMENT_H
#define TST_SETTLEMENT_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>

#include "SSAlgorithms.h"
#include "SettlementCalculation.h"

using namespace testing;
using namespace std;
/*
Point getP(int _heigh, int x, int y) {
  std::string height = std::to_string(_heigh);
  Point p(Coordinates(x, y));
  p.addProperty("height", height);
  p.addProperty("visible", "false");

  return p;
}

struct Settlement1Fixture : public testing::Test {
  vector<FilledPolygon> lakes;

  SettlementCalculation sc;

  void SetUp() override {
    vector<Point> dem;

    for (int i = 0; i <= 255; i++) {
      if (i >= 77 && i <= 84) {
        dem.push_back(getP(15000, (i % 16) * 2, i / 16 * 2));
        continue;
      }

      dem.push_back(getP(100, (i % 16) * 2, i / 16 * 2));
    }

    FilledPolygon lake;
    lake.addCoordinate(Coordinates(13, 20));
    lake.addCoordinate(Coordinates(7, 20));
    lake.addCoordinate(Coordinates(7, 12));
    lake.addCoordinate(Coordinates(13, 12));

    lakes.push_back(lake);

    ParsersCommand pc;
    pc.getParser(JSON)->savePoints(dem, "demTest");
    pc.getParser(JSON)->saveFilledPolygons(lakes, "lakesTest");
    pc.getParser(JSON)->saveFilledPolygons(lakes, "swTest");
    pc.getParser(JSON)->saveFilledPolygons(lakes, "badTest");
  }

  void TearDown() override { lakes.clear(); }
};
*/ /*
TEST_F(Settlement1Fixture, TestSettlement) {
  SettlementCalculation sc("lakesTest", "swTest", "badTest", "demTest", 16);

  FilledPolygon f;
  f.addCoordinate(Coordinates(18, 22));
  f.addCoordinate(Coordinates(19, 20));
  f.addCoordinate(Coordinates(20, 21));

  vector<Point> settlement =
      sc.getBestSettlement(f, 0, 120, 70, 2.5, 0, 20, 2, 3, 11, 22, 135);

  EXPECT_EQ(settlement[0] == Point(Coordinates(6, 14)), true);
  EXPECT_EQ(settlement[1] == Point(Coordinates(6, 18)), true);
  EXPECT_EQ(settlement[2] == Point(Coordinates(2, 14)), true);
}
*//*
TEST_F(Settlement1Fixture, TestSettlementGetFields) {
  SettlementCalculation sc("lakesTest", "swTest", "badTest", "demTest", 16);

  FilledPolygon f;
  f.addCoordinate(Coordinates(18, 22));
  f.addCoordinate(Coordinates(19, 20));
  f.addCoordinate(Coordinates(20, 21));

  vector<Point> settlement =
      sc.getBestSettlement(f, 0, 120, 70, 2.5, 0, 20, 2, 3, 11, 22, 135);



FilledPolygon getFrontView() { return frontZone; }


vector<vector<Point>> getCoverResult() { return coverResult; }
*/
/*
  EXPECT_EQ(sc.getWidth(), 31);
  EXPECT_EQ(sc.getLength(), 31);

  string str = sc.getTCZ().getProperty("view");

  EXPECT_EQ(sc.getProtectionObj().getPoints().at(0) == Coordinates(18, 22),
            true);
  EXPECT_EQ(sc.getTCZ().getProperty("view").compare("tcz") == 0, true);
  EXPECT_EQ(sc.getAWZone().getProperty("view").compare("awzone") == 0, true);
  EXPECT_EQ(sc.getProtectionObj().getProperty("view").compare("obj") == 0,
            true);
  EXPECT_EQ(sc.getRadarView().getProperty("view").compare("radarzone") == 0,
            true);
  EXPECT_EQ(sc.getFrontView().getProperty("view").compare("frontzone") == 0,
            true);
}
*//*
TEST(FilledPolygonTest, TestGetAWZone) {
  FilledPolygon f;
  f.addCoordinate(Coordinates(18, 22));
  f.addCoordinate(Coordinates(19, 20));
  f.addCoordinate(Coordinates(20, 21));

  FilledPolygon f1 = f.getAviationWeapons(2);

  EXPECT_EQ(f1.getPoints().size(), 3);
}*/

/* vector<Point> getBestSettlement(
      FilledPolygon protectionObject, float antennaHeight, float maxAngle,
      float minAngle, float shifAngle, const float flightAltitude,
      const float potentialRange, const float AWRange, size_t radarsNum,
      float ZRKRange, size_t frontWidth, float impactAngle) */
#endif  // TST_SETTLEMENT_H
