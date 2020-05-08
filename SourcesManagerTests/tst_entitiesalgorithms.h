#ifndef TST_ENTITIESALGORITHMS_H
#define TST_ENTITIESALGORITHMS_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "Algorithms.h"

using namespace testing;

using namespace std;

TEST(TestEntitiesAlgorithms, TestIntersection) {
  Coordinates s(2, 3);
  Coordinates e(3, 1);
  Coordinates s1(7, 3);
  Coordinates e1(6, 1);
  Coordinates p(1, 2);
  Coordinates rez(2.5, 2);
  Coordinates rez1(6.5, 2);
  Coordinates bad(-1000000, -1000000);

  EXPECT_EQ(intersPointLineByOX(p, s, e) == rez, true);
  EXPECT_EQ(intersPointLineByOX(p, e, s) == rez, true);
  EXPECT_EQ(intersPointLineByOX(p, s1, e1) == rez1, true);
  EXPECT_EQ(intersPointLineByOX(p, e1, s1) == rez1, true);
  EXPECT_EQ(intersPointLineByOX(bad, e1, s1) == bad, true);
  EXPECT_EQ(intersPointLineByOX(Coordinates(1000000, 1000000), e1, s1) == bad,
            true);
}

#endif  // TST_ENTITIESALGORITHMS_H
