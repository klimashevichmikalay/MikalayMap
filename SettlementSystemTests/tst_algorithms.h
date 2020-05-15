#ifndef TST_TESTFINDDISTANCE_H
#define TST_TESTFINDDISTANCE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "SSAlgorithms.h"

using namespace testing;

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

#endif  // TST_TESTFINDDISTANCE_H
