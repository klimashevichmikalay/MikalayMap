#ifndef TST_SETVISIBLEPOINTS_H
#define TST_SETVISIBLEPOINTS_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>

#include "SSAlgorithms.h"

using namespace testing;
using namespace std;

Point getP(int _heigh) {
  std::string height = std::to_string(_heigh);
  Point p;
  p.addProperty("height", height);
  p.addProperty("visible", "false");

  return p;
}

struct DEMFixture : public testing::Test {
  size_t maxY = 8;
  vector<vector<Point>> DEM;
  vector<Point> v0;
  vector<Point> v1;
  vector<Point> v2;
  vector<Point> v3;
  vector<Point> v4;
  vector<Point> v5;
  vector<Point> v6;
  vector<Point> v7;
  vector<Point> v8;
  vector<Point> v9;

  void SetUp() override {
    for (size_t i = 0; i < maxY; i++) {
      v3.push_back(getP(750));

      if (i == 0) {
        v7.push_back(getP(100));
        v8.push_back(getP(100));
        v9.push_back(getP(100));
      }

      if (i == 1 || i == 2) {
        v7.push_back(getP(-45));
        v8.push_back(getP(-45));
        v9.push_back(getP(-45));
      }

      if (i < 3) {
        v0.push_back(getP(50));
        v1.push_back(getP(50));
        v2.push_back(getP(50));
        v4.push_back(getP(50));
        v5.push_back(getP(50));
        v6.push_back(getP(50));
      }

      if (i == 3) {
        v0.push_back(getP(750));
        v1.push_back(getP(750));
        v2.push_back(getP(750));

        v4.push_back(getP(50));
        v5.push_back(getP(50));
        v6.push_back(getP(50));

        v7.push_back(getP(50));
        v8.push_back(getP(50));
        v9.push_back(getP(50));
      }

      if (i > 3) {
        v0.push_back(getP(50));
        v1.push_back(getP(50));
        v2.push_back(getP(50));
        v4.push_back(getP(50));
      }

      if (i == 4) {
        v6.push_back(getP(50));
        v7.push_back(getP(750));
        v8.push_back(getP(50));
        v9.push_back(getP(50));
      }

      if (i > 4) {
        v7.push_back(getP(50));
        v8.push_back(getP(50));
        v9.push_back(getP(50));
      }

      if (i == 5) {
        v6.push_back(getP(750));
      }

      if (i == 4 || i == 5) {
        v5.push_back(getP(50));
      }

      if (i == 6 || i == 7) {
        v5.push_back(getP(100));
        v6.push_back(getP(100));
      }
    }

    DEM.push_back(v0);
    DEM.push_back(v1);
    DEM.push_back(v2);
    DEM.push_back(v3);
    DEM.push_back(v4);
    DEM.push_back(v5);
    DEM.push_back(v6);
    DEM.push_back(v7);
    DEM.push_back(v8);
    DEM.push_back(v9);
  }

  void TearDown() override {
    v0.clear();
    v1.clear();
    v2.clear();
    v3.clear();
    v4.clear();
    v5.clear();
    v6.clear();
    v7.clear();
    v8.clear();
    v0.clear();
    DEM.clear();
  }
};

TEST_F(DEMFixture, TestFindVisiblePoint) {
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 1, 0, DEM, 50, 10000);    //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 2, -1, DEM, 50, 10000);   //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 0, 1, DEM, 50, 10000);    //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 1, 1, DEM, 50, 10000);    //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 1, 2, DEM, 50, 10000);    //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 2, 1, DEM, 50, 10000);    //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 0, -1, DEM, 50, 10000);   //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, -1, -1, DEM, 50, 10000);  //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 1, -1, DEM, 50, 10000);   //+
  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, -1, 0, DEM, 50, 10000);   //+
  // not visible
  EXPECT_EQ(DEM[0][3].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[1][3].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[2][3].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[3][3].getProperty("visible").compare("false") == 0, true);  //+

  EXPECT_EQ(DEM[7][4].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[7][5].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[7][6].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[7][7].getProperty("visible").compare("false") == 0, true);  //+

  EXPECT_EQ(DEM[7][1].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[7][2].getProperty("visible").compare("false") == 0, true);  //+

  EXPECT_EQ(DEM[6][5].getProperty("visible").compare("false") == 0, true);  //+
  EXPECT_EQ(DEM[5][7].getProperty("visible").compare("false") == 0, true);  //+

  EXPECT_EQ(DEM[3][7].getProperty("visible").compare("false") == 0, true);  //+

  // visible
  EXPECT_EQ(DEM[7][0].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[8][3].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[9][3].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[8][4].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[9][5].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[9][4].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[8][5].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[9][7].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[6][4].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[5][5].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[4][6].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[6][3].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[5][3].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[4][3].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[4][0].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[5][1].getProperty("visible").compare("true") == 0, true);  //+
  EXPECT_EQ(DEM[6][2].getProperty("visible").compare("true") == 0, true);  //+
}

TEST_F(DEMFixture, TestAllCoverage) {
  Point radarPos;
  radarPos.addProperty("height", "80");
  findCoveragePoints(radarPos, 20, 120, 80, 10, DEM, Coordinates(3, 7), 20,
                     10000, 100);
}

/*
void findCoveragePoints(Point radarPos, float antennaHeight, float maxAngle,
                        float minAngle, float shifAngle,
                        vector<vector<Point>> &DEM, Coordinates startInMatrix,
                        const float flightAltitude, const float potentialRange,
                        float distance2Points)

    */

#endif  // TST_SETVISIBLEPOINTS_H
