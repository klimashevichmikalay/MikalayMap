#ifndef TST_TRIANGLE_H
#define TST_TRIANGLE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Coordinates.h"
#include "Triangle.h"

using namespace testing;
using namespace figureTypes;
using namespace std;

TEST(TriagnleTests, TestException) {
  Triangle t;
  t.addCoordinate(Coordinates(1, 1));
  t.addCoordinate(Coordinates(2, 4));
  t.addCoordinate(Coordinates(5, 8));

  EXPECT_THROW(t.addCoordinate(Coordinates(5, 8));, std::logic_error);
}

TEST(TriagnleTests, TestIsInsidePoint) {
  Triangle t;
  t.addCoordinate(Coordinates(0, 0));
  t.addCoordinate(Coordinates(0, 5));
  t.addCoordinate(Coordinates(5, 0));

  EXPECT_EQ(t.isInside(Coordinates(1, 1)), true);
  EXPECT_EQ(t.isInside(Coordinates(2, 2)), true);
  EXPECT_EQ(t.isInside(Coordinates(10, 10)), false);
}

TEST(TriagnleTests, TestIsInsidePointExeption) {
  Triangle t;
  t.addCoordinate(Coordinates(0, 0));
  t.addCoordinate(Coordinates(0, 5));

  EXPECT_THROW(t.isInside(Coordinates(5, 8));, std::logic_error);
}

#endif  // TST_TRIANGLE_
