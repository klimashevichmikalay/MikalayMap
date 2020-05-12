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

#endif  // TST_TESTFINDDISTANCE_H
