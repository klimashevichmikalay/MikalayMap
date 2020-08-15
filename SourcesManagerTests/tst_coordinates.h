#ifndef TST_COORDINATES_H
#define TST_COORDINATES_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Coordinates.h"

using namespace testing;
using namespace Geometry;

TEST(CoordinatesTests, Compare) {
  Coordinates c(31.49999, -0.129559);
  Coordinates c1(31.4999, -0.12955);
  Coordinates c2(31.4949, -0.12955);

  EXPECT_EQ(c == c1, true);
  EXPECT_EQ(c2 == c1, false);
}

TEST(CoordinatesTests, DefaultConstr) {
  Coordinates c;

  EXPECT_EQ(c.getX(), 0);
  EXPECT_EQ(c.getY(), 0);
}

TEST(CoordinatesTests, NumsConstr) {
  Coordinates c(10, 11);

  EXPECT_EQ(c.getX(), 10);
  EXPECT_EQ(c.getY(), 11);
}

TEST(CoordinatesTests, SetGet) {
  Coordinates c;
  Coordinates c1(11, 12);

  c.setX(1);
  c.setY(2);
  c1.setX(3);
  c1.setY(4);

  EXPECT_EQ(c.getX(), 1);
  EXPECT_EQ(c.getY(), 2);
  EXPECT_EQ(c1.getX(), 3);
  EXPECT_EQ(c1.getY(), 4);
}

TEST(CoordinatesTests, Assigment) {
  Coordinates c(22.45, 11.446);
  Coordinates c1 = c;

  EXPECT_EQ(c1.getX(), 22.45);
  EXPECT_EQ(c1.getY(), 11.446);
  EXPECT_EQ(c1 == c, true);
}

TEST(CoordinatesTests, Ref) {
  Coordinates c1;
  c1.refX() = 14;
  c1.refY() = 13;

  EXPECT_EQ(c1.getX(), 14);
  EXPECT_EQ(c1.getY(), 13);
}

TEST(CoordinatesTests, Mult) {
  Coordinates c1;
  Coordinates c2;

  c1.refX() = 1;
  c1.refY() = 3;
  c2.refY() = 4;
  c2.refX() = 2;

  c1.mult(2);
  c2.mult(0.5);

  EXPECT_EQ(c1.getX(), 2);
  EXPECT_EQ(c1.getY(), 6);
  EXPECT_EQ(c2.getX(), 1);
  EXPECT_EQ(c2.getY(), 2);
}

#endif  // TST_COORDINATES_H
