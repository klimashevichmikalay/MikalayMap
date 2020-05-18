#ifndef TST_SETTLEMENT_H
#define TST_SETTLEMENT_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>

#include "SSAlgorithms.h"
#include "SettlementCalculation.h"

using namespace testing;
using namespace std;

TEST(SettlementTest, TestGenTriangles) {
  vector<vector<Point>> DEM;
  for (size_t i = 0; i <= 1000; i += 100) {
    vector<Point> vToAdd;
    for (size_t j = 0; j <= 1000; j += 100) {
      vToAdd.push_back(Point(Coordinates(j, i)));
    }
    DEM.push_back(vToAdd);
  }

  FilledPolygon rz;
  rz.addCoordinate(Coordinates(750, 750));
  rz.addCoordinate(Coordinates(50, 750));
  rz.addCoordinate(Coordinates(50, 50));
  rz.addCoordinate(Coordinates(750, 50));

  MultiPoint mp = getTZHeights(DEM, rz);

  SettlementCalculation sc;

  sc.genTriangles(mp, 2, Coordinates(4, 4));
  EXPECT_EQ(sc.getTriangles().size(), 16);
  EXPECT_EQ(sc.getPointsFromTriangles(sc.getTriangles()).size(), 9);
}

#endif  // TST_SETTLEMENT_H
