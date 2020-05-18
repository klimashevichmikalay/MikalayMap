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

TEST(SettlementTest, TestGetPointsCombination) {
  Triangle t1;
  t1.addCoordinate(Coordinates(3, 1));
  t1.addCoordinate(Coordinates(3, 3));
  t1.addCoordinate(Coordinates(5, 3));

  Triangle t2;
  t2.addCoordinate(Coordinates(3, 1));
  t2.addCoordinate(Coordinates(5, 1));
  t2.addCoordinate(Coordinates(5, 3));

  Triangle t3;
  t3.addCoordinate(Coordinates(3, 1));
  t3.addCoordinate(Coordinates(3, 3));
  t3.addCoordinate(Coordinates(5, 1));

  Triangle t4;
  t4.addCoordinate(Coordinates(5, 1));
  t4.addCoordinate(Coordinates(3, 3));
  t4.addCoordinate(Coordinates(5, 3));

  vector<Triangle> triangles;
  triangles.push_back(t1);
  triangles.push_back(t2);
  triangles.push_back(t3);
  triangles.push_back(t4);

  vector<vector<int>> combinations;

  vector<int> c1;
  c1.push_back(0);
  c1.push_back(1);

  vector<int> c2;
  c2.push_back(0);
  c2.push_back(2);

  vector<int> c3;
  c3.push_back(0);
  c3.push_back(3);

  vector<int> c4;
  c4.push_back(1);
  c4.push_back(2);

  vector<int> c5;
  c5.push_back(1);
  c5.push_back(3);

  vector<int> c6;
  c6.push_back(2);
  c6.push_back(3);

  combinations.push_back(c1);
  combinations.push_back(c2);
  combinations.push_back(c3);
  combinations.push_back(c4);
  combinations.push_back(c5);
  combinations.push_back(c6);

  /* */

  SettlementCalculation sc;

  vector<vector<Point>> points =
      sc.getPermutationsPoints(combinations, triangles);

  for (size_t i = 0; i < points.size(); i++) {
    EXPECT_EQ(points[i].size(), 4);
  }
}

#endif  // TST_SETTLEMENT_H
