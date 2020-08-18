#ifndef TST_SETTLEMENTSYSTEMALGORITHMS_H
#define TST_SETTLEMENTSYSTEMALGORITHMS_H

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

#include <string>

#include "MultiPoint.h"
#include "SettlementSystemAlgorithms.h"

using namespace testing;
using namespace Geometry;
using namespace SettlementAlgorithms;

TEST(SettlementAlgorithmsTests, LinesIntersection) {
  Point W(Coordinates(0, 1));
  Point Z(Coordinates(1, 0));

  Point A(Coordinates(3, 2));
  Point B(Coordinates(6, 5));

  Point C(Coordinates(3, 3));
  Point D(Coordinates(6.5, -0.5));

  Point R(Coordinates(5.5, -1.5));
  Point M(Coordinates(7, 0));

  EXPECT_TRUE(linesIntersection(&W, &Z, &C, &D) == nullptr);
  EXPECT_TRUE(linesIntersection(&W, &Z, &C, nullptr) == nullptr);

  EXPECT_TRUE(*linesIntersection(&A, &B, &C, &D) ==
              Point(Coordinates(3.5, 2.5)));
  EXPECT_TRUE(*linesIntersection(&M, &R, &C, &D) == D);
}

//Создается квадратная матрица высот 5 на 5
struct DEM1Fixture : public testing::Test {
  MultiPoint DEM;

  void SetUp() override {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; j++)
        DEM.addObject(Point(Coordinates(i, j)));
  }

  void TearDown() override { DEM.clear(); }
};

TEST_F(DEM1Fixture, ChekDEMInex) {
  Point P1(Coordinates(0, 1));
  Point P2(Coordinates(1, 0));
  Point P3(Coordinates(3, 2));
  Point P4(Coordinates(6, 5));

  EXPECT_EQ(DEM.getSZ(), 25);

  EXPECT_TRUE(chekDEMIndex(0, 0, DEM, 5));
  EXPECT_TRUE(chekDEMIndex(4, 4, DEM, 5));
  EXPECT_TRUE(chekDEMIndex(2, 3, DEM, 5));

  EXPECT_FALSE(chekDEMIndex(5, 3, DEM, 5));
  EXPECT_FALSE(chekDEMIndex(3, 5, DEM, 5));
  EXPECT_FALSE(chekDEMIndex(6, 6, DEM, 5));
}

TEST_F(DEM1Fixture, GetFramingCell) {
  DEMCell* c0 = getFramingCell(Point(Coordinates(3.25, 3.25)), DEM, 5);
  DEMCell* c1 = getFramingCell(Point(Coordinates(0, 0.75)), DEM, 5);
  DEMCell* c2 = getFramingCell(Point(Coordinates(1.5, 0.75)), DEM, 5);

  // nullptr
  DEMCell* c3 = getFramingCell(Point(Coordinates(5, 5)), DEM, 5);
  DEMCell* c4 = getFramingCell(Point(Coordinates(0, 5)), DEM, 5);
  DEMCell* c5 = getFramingCell(Point(Coordinates(4, 4)), DEM, 5);
  DEMCell* c6 = getFramingCell(Point(Coordinates(1, 4)), DEM, 5);

  EXPECT_TRUE(c3 == nullptr);
  EXPECT_TRUE(c4 == nullptr);
  EXPECT_TRUE(c5 == nullptr);
  EXPECT_TRUE(c6 == nullptr);

  EXPECT_TRUE(*(c0->topLeft) == Point(Coordinates(3, 3)));
  EXPECT_TRUE(*(c0->topRight) == Point(Coordinates(3, 4)));
  EXPECT_TRUE(*(c0->lowerLeft) == Point(Coordinates(4, 3)));
  EXPECT_TRUE(*(c0->lowerRight) == Point(Coordinates(4, 4)));

  EXPECT_TRUE(*(c1->topLeft) == Point(Coordinates(0, 0)));
  EXPECT_TRUE(*(c1->topRight) == Point(Coordinates(0, 1)));
  EXPECT_TRUE(*(c1->lowerLeft) == Point(Coordinates(1, 0)));
  EXPECT_TRUE(*(c1->lowerRight) == Point(Coordinates(1, 1)));

  EXPECT_TRUE(*(c2->topLeft) == Point(Coordinates(0, 1)));
  EXPECT_TRUE(*(c2->topRight) == Point(Coordinates(0, 2)));
  EXPECT_TRUE(*(c2->lowerLeft) == Point(Coordinates(1, 1)));
  EXPECT_TRUE(*(c2->lowerRight) == Point(Coordinates(1, 2)));
}

#endif  // TST_SETTLEMENTSYSTEMALGORITHMS_H
