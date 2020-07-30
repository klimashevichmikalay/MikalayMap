#ifndef TST_POINT_H
#define TST_POINT_H
/*
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>

#include "ParsersAll.h"
#include "Point.h"

using namespace testing;
using namespace figureTypes;

TEST(PointTests, TestScale) {
  Point p(Coordinates(2, 4));
  Point p1(Coordinates(1, 2));

  p.scalingByFactor(2, false);
  p1.scalingByFactor(2, true);

  EXPECT_EQ(p.getX(), 4);
  EXPECT_EQ(p.getY(), 8);
  EXPECT_EQ(p1.getX(), 1);
  EXPECT_EQ(p1.getY(), 2);
}

TEST(PointTests, TestShift) {
  Point p(Coordinates(2, 4));
  p.minusDelta(Coordinates(1, 1));

  EXPECT_EQ(p.getX(), 1);
  EXPECT_EQ(p.getY(), 3);
}

TEST(PointTests, PointDefaultConstr) {
  Point p;

  EXPECT_EQ(p.getName(), "");
  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getX(), 0);
  EXPECT_EQ(p.getY(), 0);
}

TEST(PointTests, PointInitWithStr) {
  Point p("name");

  EXPECT_EQ(p.getName(), "name");
  EXPECT_NE(p.getName(), "");
}

TEST(PointTests, PointInitWithCStr) {
  char *name = new char[20];
  strcpy(name, "new name");

  Point p(name);
  delete[] name;

  EXPECT_EQ(p.getName(), "new name");
}

TEST(PointTests, PointInitWithLatLon) {
  Coordinates location(10, 11);
  Point p(location);

  EXPECT_EQ(p.getName(), "");
  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getX(), 10);
  EXPECT_EQ(p.getY(), 11);
}

TEST(PointTests, PointInitWithLatLonStr) {
  Coordinates location(10, 11);
  Point p("new name", location);

  EXPECT_EQ(p.getName(), "new name");
  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getX(), 10);
  EXPECT_EQ(p.getY(), 11);
  EXPECT_EQ(p.getName(), "new name");
}

TEST(PointTests, PointInitWithLatLonCStr) {
  char *name = new char[20];
  strcpy(name, "new name");

  Coordinates location(10, 11);
  Point p(name, location);
  delete[] name;

  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getX(), 10);
  EXPECT_EQ(p.getY(), 11);
  EXPECT_EQ(p.getName(), "new name");
}

TEST(PointTests, PointTestSettersGettersProps) {
  char *name = new char[20];
  strcpy(name, "new name");

  Point p;
  p.setName(name);
  delete[] name;
  p.addProperty("prop0", "value0");
  p.addProperty("prop1", "value1");
  p.setX(100);
  p.setY(200);
  p.delProperty("prop0");

  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getName(), "new name");
  EXPECT_EQ(p.getProperty("name"), "new name");
  EXPECT_EQ(p.getProperty("prop0"), "");
  EXPECT_EQ(p.getProperty("prop1"), "value1");
  EXPECT_EQ(p.getX(), 100);
  EXPECT_EQ(p.getY(), 200);
}

TEST(PointTests, TestCoordinates) {
  Point p;

  EXPECT_EQ(p.getName(), "");
  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getX(), 0);
  EXPECT_EQ(p.getY(), 0);
}

TEST(PointTests, TestCompare) {
  Point p("point", Coordinates(1, 2));
  Point p2("point", Coordinates(1, 2));
  Point p3("point3", Coordinates(1, 2));
  Point p4("point", Coordinates(2, 2));

  EXPECT_EQ(p == p2, true);
  EXPECT_EQ(p == p3, false);
  EXPECT_EQ(p == p4, false);
}

//#include "ParsersAll.h"
TEST(PointTests, TestSerializeAndDesirealize) {
  Point p("point", Coordinates(1, 2));
  p.addProperty("prop0", "val0");
  p.addProperty("prop1", "val");
  p.addProperty("prop2", "val2");
  p.setScale(0.88);

  rapidjson::StringBuffer sb;
  rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(sb);
  pointToJSON(p, writer);
  Point pAfter = jsonToPoint(sb.GetString());

  EXPECT_EQ(p == pAfter, true);
}

vector<vector<Point>> f(vector<vector<Point>> v) {
  Point p1("point1", Coordinates(11, 21));
  p1.addProperty("prop01", "val0");
  p1.addProperty("prop11", "val");
  p1.addProperty("prop21", "val2");
  p1.setScale(0.88);
  vector<Point> v1;
  v1.push_back(p1);
  v.push_back(v1);
  return v;
}

TEST(PointTests, TestCopyCnstrct) {
  Point p("point", Coordinates(1, 2));
  p.addProperty("prop0", "val0");
  p.addProperty("prop1", "val1");
  p.addProperty("prop2", "val2");
  p.setScale(0.88);

  vector<Point> v;
  v.push_back(p);

  vector<vector<Point>> vv;
  vv.push_back(v);

  vector<vector<Point>> v1 = f(vv);

  vector<vector<Point>> v2;
  v2.swap(v1);

  EXPECT_EQ(v2[0][0].getProperty("name").compare("point") == 0, true);
  EXPECT_EQ(v2[0][0].getProperty("prop0").compare("val0") == 0, true);
  EXPECT_EQ(v2[0][0].getProperty("prop1").compare("val1") == 0, true);
  EXPECT_EQ(v2[0][0].getProperty("prop2").compare("val2") == 0, true);

  EXPECT_EQ(v2[1][0].getProperty("name").compare("point1") == 0, true);
  EXPECT_EQ(v2[1][0].getProperty("prop01").compare("val0") == 0, true);
  EXPECT_EQ(v2[1][0].getProperty("prop11").compare("val") == 0, true);
  EXPECT_EQ(v2[1][0].getProperty("prop21").compare("val2") == 0, true);
}
*/
#endif  // TST_POINT_H
