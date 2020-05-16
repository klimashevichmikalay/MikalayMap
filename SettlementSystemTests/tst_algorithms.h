#ifndef TST_TESTFINDDISTANCE_H
#define TST_TESTFINDDISTANCE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "SSAlgorithms.h"

using namespace testing;

struct DEM1Fixture : public testing::Test {
  vector<vector<Point>> DEM;

  void SetUp() override {
    for (size_t i = 0; i <= 800; i += 100) {
      vector<Point> vToAdd;
      for (size_t j = 0; j <= 1200; j += 100) {
        vToAdd.push_back(Point(Coordinates(j, i)));
      }
      DEM.push_back(vToAdd);
    }
  }

  void TearDown() override {
    for (size_t i = 0; i < DEM.size(); i++) {
      DEM[i].clear();
    }

    DEM.clear();
  }
};

struct DEM2Fixture : public testing::Test {
  vector<vector<Point>> DEM;

  void SetUp() override {
    for (size_t i = 0; i <= 1200; i += 50) {
      vector<Point> vToAdd;
      for (size_t j = 0; j <= 1200; j += 50) {
        vToAdd.push_back(Point(Coordinates(j, i)));
      }
      DEM.push_back(vToAdd);
    }
  }

  void TearDown() override {
    for (size_t i = 0; i < DEM.size(); i++) {
      DEM[i].clear();
    }

    DEM.clear();
  }
};

TEST(SSAlgorithmsTests, TestFindDistance) {
  EXPECT_EQ(fabs(findDistance(Coordinates(0, 0), Coordinates(2, 2)) -
                 sqrt(2) * 2) < 0.0001,
            true);
  EXPECT_EQ(fabs(findDistance(Coordinates(2, 2), Coordinates(0, 0)) -
                 sqrt(2) * 2) < 0.0001,
            true);

  EXPECT_EQ(
      fabs(findDistance(Coordinates(0, 0), Coordinates(3, 0)) - 3) < 0.0001,
      true);

  EXPECT_EQ(fabs(findDistance(Coordinates(-2, -2), Coordinates(-4, -4)) -
                 sqrt(2) * 2) < 0.0001,
            true);
}

TEST(SSAlgorithmsTests, TestFindAgle) {
  Coordinates p(0, 0);
  Coordinates p1(3, 0);
  Coordinates p2(0, -3);
  Coordinates p4(3, -3);
  Coordinates p5(1, 2);
  Coordinates p6(3, 2);
  Coordinates p7(3, 4);

  float angl1 = findAgle(p, p1, p2);   // 90
  float angl5 = findAgle(p6, p5, p7);  // 90
  float angl2 = findAgle(p2, p1, p);   // 45
  float angl3 = findAgle(p, p1, p4);   // 45
  float angl4 = findAgle(p5, p6, p7);  // 45

  EXPECT_EQ(fabs(angl1 - 90.0) < 0.0001, true);
  EXPECT_EQ(fabs(angl5 - 90.0) < 0.0001, true);
  EXPECT_EQ(fabs(angl2 - 45.0) < 0.0001, true);
  EXPECT_EQ(fabs(angl3 - 45.0) < 0.0001, true);
  EXPECT_EQ(fabs(angl4 - 45.0) < 0.0001, true);
}

TEST(SSAlgorithmsTests, TestGetFrontZone) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(8.5, 7.5));
  fp.addCoordinate(Coordinates(7, 8.5));
  fp.addCoordinate(Coordinates(6, 7.5));
  fp.addCoordinate(Coordinates(7.5, 6));

  FilledPolygon fz = getFrontZone(fp, 5, 135, 20, 12);
  vector<Coordinates> points = fz.getPoints();

  float angl1 =
      findAgle(points[1], points[2], Coordinates(0, points[1].getY()));
  float angl2 = findAgle(points[0], points[3],
                         Coordinates(points[3].getX(), points[0].getY()));

  EXPECT_EQ(fabs(angl1 - 45.0) < 5, true);
  EXPECT_EQ(fabs(angl2 - 45.0) < 5, true);
}

TEST(SSAlgorithmsTests, TestGetFrontZone2) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(8.5, 7.5));
  fp.addCoordinate(Coordinates(7, 8.5));
  fp.addCoordinate(Coordinates(6, 7.5));
  fp.addCoordinate(Coordinates(7.5, 6));

  FilledPolygon fz = getFrontZone(fp, 5, 45, 20, 12);
  vector<Coordinates> points = fz.getPoints();

  float angl1 = findAgle(points[1], points[2],
                         Coordinates(points[2].getX(), points[1].getY()));
  float angl2 = findAgle(points[0], points[3],
                         Coordinates(points[3].getX(), points[0].getY()));

  EXPECT_EQ(fabs(angl1 - 45.0) < 5, true);
  EXPECT_EQ(fabs(angl2 - 45.0) < 5, true);
}

TEST(SSAlgorithmsTests, TestGetFrontZone3) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(8.5, 7.5));
  fp.addCoordinate(Coordinates(7, 8.5));
  fp.addCoordinate(Coordinates(6, 7.5));
  fp.addCoordinate(Coordinates(7.5, 6));

  FilledPolygon fz = getFrontZone(fp, 5, 110, 20, 12);
  vector<Coordinates> points = fz.getPoints();

  float angl1 = findAgle(points[1], points[2],
                         Coordinates(points[2].getX(), points[1].getY()));
  float angl2 = findAgle(points[0], points[3],
                         Coordinates(points[3].getX(), points[0].getY()));

  EXPECT_EQ(fabs(angl1 - 70.0) < 5, true);
  EXPECT_EQ(fabs(angl2 - 70.0) < 5, true);
}

TEST(SSAlgorithmsTests, TestGetFrontZone4) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(8.5, 7.5));
  fp.addCoordinate(Coordinates(7, 8.5));
  fp.addCoordinate(Coordinates(6, 7.5));
  fp.addCoordinate(Coordinates(7.5, 6));

  FilledPolygon fz = getFrontZone(fp, 5, 20, 20, 12);
  vector<Coordinates> points = fz.getPoints();

  float angl1 = findAgle(points[1], points[2],
                         Coordinates(points[2].getX(), points[1].getY()));
  float angl2 = findAgle(points[0], points[3],
                         Coordinates(points[3].getX(), points[0].getY()));

  EXPECT_EQ(fabs(angl1 - 20.0) < 5, true);
  EXPECT_EQ(fabs(angl2 - 20.0) < 5, true);
}

TEST(SSAlgorithmsTests, TestGetFrontZone5) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(8.5, 7.5));
  fp.addCoordinate(Coordinates(7, 8.5));
  fp.addCoordinate(Coordinates(6, 7.5));
  fp.addCoordinate(Coordinates(7.5, 6));

  FilledPolygon fz = getFrontZone(fp, 5, 179, 20, 12);
  vector<Coordinates> points = fz.getPoints();

  float angl1 = findAgle(points[1], points[0], points[3]);  //
  float angl2 = findAgle(points[0], points[1], points[2]);

  EXPECT_EQ(fabs(angl1 - 180.0) < 10, true);
  EXPECT_EQ(angl2 < 5, true);
}

TEST(SSAlgorithmsTests, TestGetFrontZone6) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(8.5, 7.5));
  fp.addCoordinate(Coordinates(7, 8.5));
  fp.addCoordinate(Coordinates(6, 7.5));
  fp.addCoordinate(Coordinates(7.5, 6));

  FilledPolygon fz = getFrontZone(fp, 5, 89, 20, 12);
  vector<Coordinates> points = fz.getPoints();

  float angl1 = findAgle(points[1], points[0], points[2]);
  float angl2 = findAgle(points[0], points[1], points[3]);

  EXPECT_EQ(fabs(angl1 - 90.0) < 5, true);
  EXPECT_EQ(fabs(angl2 - 90.0) < 5, true);
}

/*FilledPolygon getFrontZone(FilledPolygon AWZone, size_t frontWidth,
                           float impactAngle, float lengthField,
                           float widthField)*/

TEST(SSAlgorithmsTests, TestGetRadarZone) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(6, 3));
  fp.addCoordinate(Coordinates(4, 1));
  fp.addCoordinate(Coordinates(1, 4));
  fp.addCoordinate(Coordinates(3, 6));

  FilledPolygon rz = getRadarZone(fp, 1.414213);
  vector<Coordinates> points = rz.getPoints();
  FilledPolygon tz = getTargetZone(fp, rz);
  vector<Coordinates> points2 = tz.getPoints();

  EXPECT_EQ(points[0] == Coordinates(6, 3), true);
  EXPECT_EQ(points[1] == Coordinates(4, 1), true);
  EXPECT_EQ(points[2] == Coordinates(3, 2), true);
  EXPECT_EQ(points[3] == Coordinates(5, 4), true);

  EXPECT_EQ(points2[0] == Coordinates(5, 4), true);
  EXPECT_EQ(points2[1] == Coordinates(3, 2), true);
  EXPECT_EQ(points2[2] == Coordinates(1, 4), true);
  EXPECT_EQ(points2[3] == Coordinates(3, 6), true);
}

TEST(SSAlgorithmsTests, TestGetRadarZone2) {
  FilledPolygon fp;
  fp.addCoordinate(Coordinates(10, 1));
  fp.addCoordinate(Coordinates(8, 1));
  fp.addCoordinate(Coordinates(12, 5));
  fp.addCoordinate(Coordinates(14, 5));

  FilledPolygon rz = getRadarZone(fp, 2.828427);
  vector<Coordinates> points = rz.getPoints();

  EXPECT_EQ(points[0] == Coordinates(10, 1), true);
  EXPECT_EQ(points[1] == Coordinates(8, 1), true);
  EXPECT_EQ(points[2] == Coordinates(10, 3), true);
  EXPECT_EQ(points[3] == Coordinates(12, 3), true);
}

TEST_F(DEM1Fixture, TestGetTZHeights) {
  FilledPolygon tz1;
  FilledPolygon tz2;
  MultiPoint tzh1;
  MultiPoint tzh2;

  tz1.addCoordinate(Coordinates(700, 150));
  tz1.addCoordinate(Coordinates(500, 150));
  tz1.addCoordinate(Coordinates(200, 450));
  tz1.addCoordinate(Coordinates(400, 450));

  tz2.addCoordinate(Coordinates(1050, 150));
  tz2.addCoordinate(Coordinates(850, 150));
  tz2.addCoordinate(Coordinates(1000, 450));
  tz2.addCoordinate(Coordinates(1200, 450));

  tzh1 = getTZHeights(DEM, tz1);
  tzh2 = getTZHeights(DEM, tz2);

  vector<Point> points1 = tzh1.getPoints();
  vector<Point> points2 = tzh2.getPoints();

  EXPECT_EQ(points1.size(), 6);
  EXPECT_EQ(points2.size(), 6);

  //  Coordinates demxy1 = tzh1.getFirstByPropetry("DEMXY", "");

  EXPECT_NE(tzh1.getFirstByPropetry("DEMXY", "5 2"), nullptr);
  EXPECT_NE(tzh1.getFirstByPropetry("DEMXY", "6 2"), nullptr);
  EXPECT_NE(tzh1.getFirstByPropetry("DEMXY", "4 3"), nullptr);
  EXPECT_NE(tzh1.getFirstByPropetry("DEMXY", "5 3"), nullptr);
  EXPECT_NE(tzh1.getFirstByPropetry("DEMXY", "3 4"), nullptr);
  EXPECT_NE(tzh1.getFirstByPropetry("DEMXY", "4 4"), nullptr);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "3 3"), nullptr);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "4 2"), nullptr);
  ///
  EXPECT_NE(tzh2.getFirstByPropetry("DEMXY", "9 2"), nullptr);
  EXPECT_NE(tzh2.getFirstByPropetry("DEMXY", "10 2"), nullptr);
  EXPECT_NE(tzh2.getFirstByPropetry("DEMXY", "10 3"), nullptr);
  EXPECT_NE(tzh2.getFirstByPropetry("DEMXY", "11 3"), nullptr);
  EXPECT_NE(tzh2.getFirstByPropetry("DEMXY", "10 4"), nullptr);
  EXPECT_NE(tzh2.getFirstByPropetry("DEMXY", "11 4"), nullptr);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "9 3"), nullptr);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "10 5"), nullptr);

  // check positions
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "5 2")->getCoordinates() ==
                Coordinates(500, 200),
            true);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "6 2")->getCoordinates() ==
                Coordinates(600, 200),
            true);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "4 3")->getCoordinates() ==
                Coordinates(400, 300),
            true);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "5 3")->getCoordinates() ==
                Coordinates(500, 300),
            true);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "3 4")->getCoordinates() ==
                Coordinates(300, 400),
            true);
  EXPECT_EQ(tzh1.getFirstByPropetry("DEMXY", "4 4")->getCoordinates() ==
                Coordinates(400, 400),
            true);

  ///
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "9 2")->getCoordinates() ==
                Coordinates(900, 200),
            true);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "10 2")->getCoordinates() ==
                Coordinates(1000, 200),
            true);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "10 3")->getCoordinates() ==
                Coordinates(1000, 300),
            true);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "11 3")->getCoordinates() ==
                Coordinates(1100, 300),
            true);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "10 4")->getCoordinates() ==
                Coordinates(1000, 400),
            true);
  EXPECT_EQ(tzh2.getFirstByPropetry("DEMXY", "11 4")->getCoordinates() ==
                Coordinates(1100, 400),
            true);
}

TEST_F(DEM2Fixture, TestDem2Fixture) {
  FilledPolygon tz1;
  MultiPoint tzh1;

  tz1.addCoordinate(Coordinates(1075, 125));
  tz1.addCoordinate(Coordinates(475, 125));
  tz1.addCoordinate(Coordinates(275, 825));
  tz1.addCoordinate(Coordinates(875, 825));

  tzh1 = getTZHeights(DEM, tz1);
  vector<Point> points1 = tzh1.getPoints();

  EXPECT_EQ(points1.size(), 168);
}

TEST_F(DEM2Fixture, TestFormTriagnles) {
  FilledPolygon tz1;
  MultiPoint tzh1;

  tz1.addCoordinate(Coordinates(1075, 125));
  tz1.addCoordinate(Coordinates(475, 125));
  tz1.addCoordinate(Coordinates(275, 825));
  tz1.addCoordinate(Coordinates(875, 825));

  tzh1 = getTZHeights(DEM, tz1);
  vector<Point> points1 = tzh1.getPoints();

  EXPECT_EQ(points1.size(), 168);
}

/* MultiPoint getTZHeights(vector<vector<Point>> DEM, FilledPolygon tz) {*/

#endif  // TST_TESTFINDDISTANCE_H
