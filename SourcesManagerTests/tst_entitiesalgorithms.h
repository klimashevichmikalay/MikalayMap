#ifndef TST_ENTITIESALGORITHMS_H
#define TST_ENTITIESALGORITHMS_H

/*#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Algorithms.h"
#include "LineString.h"

using namespace testing;

using namespace std;

TEST(TestEntitiesAlgorithms, TestIntersection) {
  Coordinates s(2, 3);
  Coordinates e(3, 1);
  Coordinates s1(7, 3);
  Coordinates e1(6, 1);
  Coordinates p(1, 2);
  Coordinates *rez = new Coordinates(2.5, 2);
  Coordinates *rez1 = new Coordinates(6.5, 2);

  EXPECT_EQ(*intersPointLineByOX(p, s, e) == *rez, true);
  EXPECT_EQ(*intersPointLineByOX(p, e, s) == *rez, true);
  EXPECT_EQ(*intersPointLineByOX(p, s1, e1) == *rez1, true);
  EXPECT_EQ(*intersPointLineByOX(p, e1, s1) == *rez1, true);
  EXPECT_EQ(
      intersPointLineByOX(Coordinates(-100000, -10000), e1, s1) == nullptr,
      true);
  EXPECT_EQ(
      intersPointLineByOX(Coordinates(1000000, 1000000), e1, s1) == nullptr,
      true);

  EXPECT_EQ(
      intersPointLineByOX(Coordinates(-1000000, 1000000), e1, s1) == nullptr,
      true);

  EXPECT_EQ(
      intersPointLineByOX(Coordinates(1000000, -1000000), e1, s1) == nullptr,
      true);
}

TEST(TestEntitiesAlgorithms, TestEqualsVectors1) {
  vector<int> v0;
  vector<int> v1;
  vector<int> v2;
  vector<int> v3;

  v0.push_back(1);
  v0.push_back(2);
  v0.push_back(3);

  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);

  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(4);

  v3.push_back(1);
  v3.push_back(2);
  v3.push_back(3);
  v3.push_back(4);

  EXPECT_EQ(isEqual(v0, v1), true);
  EXPECT_EQ(isEqual(v0, v2), false);
  EXPECT_EQ(isEqual(v0, v3), false);
  EXPECT_EQ(isEqual(v1, v3), false);
}

TEST(TestEntitiesAlgorithms, TestEqualsVectors2) {
  vector<LineString> v0;
  vector<LineString> v1;
  vector<LineString> v2;
  vector<LineString> v3;

  LineString ls1;
  LineString ls2;
  LineString ls3;
  LineString ls4;
  LineString ls5;
  LineString ls6;
  LineString ls7;

  ls1.addCoordinate(Coordinates(3, 1));
  ls1.addCoordinate(Coordinates(2, 3));
  ls1.addCoordinate(Coordinates(4, 4));
  ls2.addCoordinate(Coordinates(3, 1));
  ls2.addCoordinate(Coordinates(2, 3));
  ls2.addCoordinate(Coordinates(4, 4));
  ls4.addCoordinate(Coordinates(3, 2));

  ls5.addCoordinate(Coordinates(2.58579, 0.526613));
  ls5.addCoordinate(Coordinates(1.17157, 3.35504));

  v0.push_back(ls1);
  v1.push_back(ls2);
  v0.push_back(ls3);
  v1.push_back(ls3);
  v0.push_back(ls4);
  v1.push_back(ls4);

  v2.push_back(ls5);
  v2.push_back(ls2);
  v2.push_back(ls3);
  v2.push_back(ls4);

  EXPECT_EQ(isEqual(v0, v1), true);
  EXPECT_EQ(isEqual(v0, v2), false);
  EXPECT_EQ(isEqual(v1, v2), false);
}
*/

#endif  // TST_ENTITIESALGORITHMS_H
