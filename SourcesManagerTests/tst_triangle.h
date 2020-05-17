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

TEST(TriagnleTests, TestConstructorSettersGetters) {
  Triangle t;
  Triangle t1("NAME1");

  char *name = new char[20];
  strcpy(name, "name1");
  Triangle t2(name);
  delete[] name;

  t.addProperty("prop1", "val1");

  EXPECT_EQ(t2.getName(), "name1");
  EXPECT_EQ(t1.getProperty("name"), "name1");
  EXPECT_EQ(t.getProperty("name"), "");
  EXPECT_EQ(t.getProperty("prop1"), "val1");
  EXPECT_EQ(t.getType(), TRIANGLE);
  EXPECT_EQ(t1.getType(), TRIANGLE);
  EXPECT_EQ(t2.getType(), TRIANGLE);
}

TEST(TriagnleTests, TestCompare) {
  Triangle t;
  Triangle t1;
  Triangle t2;

  t.addCoordinate(Coordinates(1, 1));
  t.addCoordinate(Coordinates(2, 3));
  t.addCoordinate(Coordinates(5, 4));

  t1.addCoordinate(Coordinates(2, 3));
  t1.addCoordinate(Coordinates(5, 4));
  t1.addCoordinate(Coordinates(1, 1));

  t2.addCoordinate(Coordinates(6, 3));
  t2.addCoordinate(Coordinates(5, 4));
  t2.addCoordinate(Coordinates(1, 1));

  EXPECT_EQ(t == t1, true);
  EXPECT_EQ(t == t2, false);
  EXPECT_EQ(t1 == t2, false);
}

#endif  // TST_TRIANGLE_
