#ifndef TST_MULTIPOINT_H
#define TST_MULTIPOINT_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include "MultiPoint.h"

using namespace testing;
using namespace figureTypes;
using namespace std;

TEST(MultiPointTests, TestDefaultConstructors) {
  BaseFigure bf("somename", POINT);

  bf.setName("somename2");

  EXPECT_EQ(bf.getName(), "somename2");
  EXPECT_NE(bf.getName(), "new name");
}

#endif  // TST_MULTIPOINT_H
