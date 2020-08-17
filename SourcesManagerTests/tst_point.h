#ifndef TST_POINT_H
#define TST_POINT_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>

#include "ParsersAll.h"
#include "Point.h"

using namespace testing;
using namespace Geometry;

TEST(PointTests, GetSetLocation) {
  Point p;

  p.setLocation(Coordinates(12, 14));

  EXPECT_EQ(p.getX(), 12);
  EXPECT_EQ(p.getY(), 14);
  EXPECT_EQ(*p.getLocation() == Coordinates(12, 14), true);
}

TEST(PointTests, Constructors) {
  Point p;
  Point p1("p1");
  Point p2(Coordinates(3, 4));
  Point p3("p3", Coordinates(3, 4));

  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p1.getType(), POINT);
  EXPECT_EQ(p2.getType(), POINT);
  EXPECT_EQ(p3.getType(), POINT);

  EXPECT_EQ(p.getName(), nullptr);
  EXPECT_EQ(p1.getName()->compare("p1"), 0);
  EXPECT_EQ(p2.getName(), nullptr);
  EXPECT_EQ(p3.getName()->compare("p3"), 0);

  EXPECT_EQ(p2.getX(), 3);
  EXPECT_EQ(p2.getY(), 4);
}

TEST(PointTests, Scale) {
  Point p(Coordinates(2, 4));
  Point p1(Coordinates(2, 4));

  p.scalingByFactor(2, false);
  p1.scalingByFactor(2, true);

  EXPECT_EQ(p.getX(), 4);
  EXPECT_EQ(p.getY(), 8);
  EXPECT_EQ(p.getScale(), 2);

  EXPECT_EQ(p1.getX(), 2);
  EXPECT_EQ(p1.getY(), 4);
  EXPECT_EQ(p1.getScale(), 2);
}

TEST(PointTests, Shift) {
  Point p(Coordinates(2, 4));

  p.shift(Coordinates(1, 1));

  EXPECT_EQ(p.getX(), 3);
  EXPECT_EQ(p.getY(), 5);
  EXPECT_EQ(p.getScale(), 1);
}

TEST(PointTests, Assign1) {
  Point p;

  p.setName("name");
  p.addProperty("prop0", "value0");
  p.addProperty("prop1", "value1");
  p.setX(100);
  p.setY(200);
  p.delProperty("prop0");

  Point p2 = p;
  Point p3;
  p3 = p;

  EXPECT_EQ(p2.getType(), POINT);
  EXPECT_EQ(p2.getName()->compare("name"), 0);
  EXPECT_EQ(p2.getProperty("name")->compare("name"), 0);
  EXPECT_EQ(p2.getProperty("prop0"), nullptr);
  EXPECT_EQ(p2.getProperty("prop1")->compare("value1"), 0);
  EXPECT_EQ(p2.getX(), 100);
  EXPECT_EQ(p2.getY(), 200);

  EXPECT_EQ(p3.getType(), POINT);
  EXPECT_EQ(p3.getName()->compare("name"), 0);
  EXPECT_EQ(p3.getProperty("name")->compare("name"), 0);
  EXPECT_EQ(p3.getProperty("prop0"), nullptr);
  EXPECT_EQ(p3.getProperty("prop1")->compare("value1"), 0);
  EXPECT_EQ(p3.getX(), 100);
  EXPECT_EQ(p3.getY(), 200);

  EXPECT_EQ(p3 == p2, true);
  EXPECT_EQ(p3 == p, true);
}

TEST(PointTests, PointTestSettersGettersProps) {
  Point p;

  p.setName("name");
  p.addProperty("prop0", "value0");
  p.addProperty("prop1", "value1");
  p.setX(100);
  p.setY(200);
  p.delProperty("prop0");

  EXPECT_EQ(p.getType(), POINT);
  EXPECT_EQ(p.getName()->compare("name"), 0);
  EXPECT_EQ(p.getProperty("name")->compare("name"), 0);
  EXPECT_EQ(p.getProperty("prop0"), nullptr);
  EXPECT_EQ(p.getProperty("prop1")->compare("value1"), 0);
  EXPECT_EQ(p.getX(), 100);
  EXPECT_EQ(p.getY(), 200);
}

TEST(PointTests, TestCompare) {
  Point p("point", Coordinates(1, 2));
  Point p2("point", Coordinates(1, 2));
  Point p3("point3", Coordinates(1, 2));
  Point p4("point", Coordinates(2, 2));
  Point p5;
  Point p6;

  p6.setScale(0.8);

  EXPECT_EQ(p5 == p6, false);
  EXPECT_EQ(p == p2, true);
  EXPECT_EQ(p == p3, false);
  EXPECT_EQ(p == p4, false);
}

TEST(PointTests, TestMult) {
  Point p;
  Point p1("point", Coordinates(1, 2));

  p.mult(22);
  p1.mult(10);

  EXPECT_EQ(p.getX(), 0);
  EXPECT_EQ(p.getY(), 0);
  EXPECT_EQ(p1.getX(), 10);
  EXPECT_EQ(p1.getY(), 20);
}

#endif  // TST_POINT_H
