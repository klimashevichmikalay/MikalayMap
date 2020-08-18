#ifndef TST_PERMUTATIONS_H
#define TST_PERMUTATIONS_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "PermutationsGenerator.h"

using namespace testing;
/*
TEST(PermutationsTest, TestGenPermutations) {
  PermutationsGenerator sc;
  vector<vector<int>> v0 = sc.getPermutations(10, 2);
  vector<vector<int>> v1 = sc.getPermutations(20, 2);

  EXPECT_EQ(v0.size(), 45);
  EXPECT_EQ(v1.size(), 190);
}
*/
#endif  // TST_PERMUTATIONS_H
