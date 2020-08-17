#ifndef TST_TRIANGLE_H
#define TST_TRIANGLE_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Coordinates.h"
#include "Triangle.h"

using namespace testing;
using namespace Geometry;
using namespace std;

TEST(TriagnleTests, Exception) {
  Triangle t;

  t.addObject(Coordinates(1, 1));
  t.addObject(Coordinates(2, 4));
  t.addObject(Coordinates(5, 8));

  EXPECT_THROW(t.addObject(Coordinates(5, 8));, std::logic_error);
}

TEST(TriagnleTests, ConstructorSettersGetters) {
  Triangle t;
  Triangle t1("NAME1");

  char* name = new char[20];
  strcpy(name, "name1");
  Triangle t2(name);
  delete[] name;

  t.addProperty("prop1", "val1");

  EXPECT_EQ(t2.getName()->compare("name1"), 0);
  EXPECT_EQ(t1.getProperty("name")->compare("name1"), 0);
  EXPECT_EQ(t.getProperty("name"), nullptr);
  EXPECT_EQ(t.getProperty("prop1")->compare("val1"), 0);
  EXPECT_EQ(t.getType(), TRIANGLE);
  EXPECT_EQ(t1.getType(), TRIANGLE);
  EXPECT_EQ(t2.getType(), TRIANGLE);
}

TEST(TriagnleTests, Compare) {
  Triangle t;
  Triangle t1;
  Triangle t2;

  t.addObject(Coordinates(1, 1));
  t.addObject(Coordinates(2, 3));
  t.addObject(Coordinates(5, 4));

  t1.addObject(Coordinates(2, 3));
  t1.addObject(Coordinates(5, 4));
  t1.addObject(Coordinates(1, 1));

  t2.addObject(Coordinates(6, 3));
  t2.addObject(Coordinates(5, 4));
  t2.addObject(Coordinates(1, 1));

  EXPECT_TRUE(t == t1);
  EXPECT_FALSE(t == t2);
  EXPECT_FALSE(t1 == t2);
}

TEST(TriagnleTests, Assigment) {
  Triangle t;
  Triangle t1("T1");

  t.addObject(Coordinates(1, 1));
  t.addObject(Coordinates(2, 3));
  t.addObject(Coordinates(5, 4));

  t.addProperty("prop", "val");

  t1.addProperty("prop0", "val0");
  t1.addProperty("prop1", "val1");
  t1.addProperty("prop2", "val2");

  t1 = t;

  EXPECT_EQ(t1.getProperty("prop0"), nullptr);
  EXPECT_EQ(t1.getProperty("prop1"), nullptr);
  EXPECT_EQ(t1.getProperty("prop2"), nullptr);
  EXPECT_EQ(t1.getProperty("prop")->compare("val"), 0);
  EXPECT_EQ(t1.getSZ(), 3);
}

TEST(TriagnleTests, Clear) {
  Triangle t;
  Triangle t1;

  t.addObject(Coordinates(1, 1));
  t.addObject(Coordinates(2, 3));
  t.addObject(Coordinates(5, 4));

  t.addProperty("prop", "val");
  t.addProperty("prop0", "val0");
  t.addProperty("prop1", "val1");
  t.addProperty("prop2", "val2");

  t1 = t;
  t.clear();

  EXPECT_EQ(t1.getProperty("prop")->compare("val"), 0);
  EXPECT_EQ(t1.getProperty("prop0")->compare("val0"), 0);
  EXPECT_EQ(t1.getProperty("prop1")->compare("val1"), 0);
  EXPECT_EQ(t1.getProperty("prop2")->compare("val2"), 0);
  EXPECT_EQ(t1.getProperty("prop2")->compare("val2"), 0);
  EXPECT_EQ(t1.getSZ(), 3);
  EXPECT_EQ(t1.end() - t1.begin(), 3);

  EXPECT_EQ(t.getProperty("prop"), nullptr);
  EXPECT_EQ(t.getProperty("prop0"), nullptr);
  EXPECT_EQ(t.getProperty("prop1"), nullptr);
  EXPECT_EQ(t.getProperty("prop2"), nullptr);
  EXPECT_EQ(t.getSZ(), 0);
  EXPECT_EQ(t.end() - t.begin(), 0);
}

#endif  // TST_TRIANGLE_
