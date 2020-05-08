#ifndef TST_COORDINATES_H
#define TST_COORDINATES_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Coordinates.h"

using namespace testing;

TEST(CoordinatesTests, TestCompare) {
  Coordinates c(31.49999, -0.129559);
  Coordinates c1(31.4999, -0.12955);

  EXPECT_EQ(c == c1, true);
}

TEST(CoordinatesTests, CoordinatesDefaultConstr) {
  Coordinates c;

  EXPECT_EQ(c.getX(), 0);
  EXPECT_EQ(c.getY(), 0);
}

TEST(CoordinatesTests, CoordinatesNumsConstr) {
  Coordinates c(10, 11);

  EXPECT_EQ(c.getX(), 10);
  EXPECT_EQ(c.getY(), 11);
}

TEST(CoordinatesTests, CoordinatesSetGet) {
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

#endif  // TST_COORDINATES_H
