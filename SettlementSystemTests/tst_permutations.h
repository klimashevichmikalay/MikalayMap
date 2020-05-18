#ifndef TST_PERMUTATIONS_H
#define TST_PERMUTATIONS_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "PermutationsGenerator.h"

using namespace testing;

TEST(PermutationsTest, TestGenPermutations) {
  PermutationsGenerator sc;
  // vector<vector<int>> v0 = sc.getPermutations(5, 3);
  // vector<vector<int>> v1 = sc.getPermutations(4, 3);

  // EXPECT_EQ(v0.size(), 10);
  // EXPECT_EQ(v1.size(), 4);
}

#endif  // TST_PERMUTATIONS_H
