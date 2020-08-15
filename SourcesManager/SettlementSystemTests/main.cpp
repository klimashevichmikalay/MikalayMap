#include <gtest/gtest.h>

#include "tst_algorithms.h"
#include "tst_core.h"
#include "tst_permutations.h"
#include "tst_settlement.h"
#include "tst_setvisiblepoints.h"
int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
