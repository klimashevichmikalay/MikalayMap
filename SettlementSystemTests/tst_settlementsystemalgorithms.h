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
      for (int j = 0; j < 5; j++) {
        DEM.addObject(Point(Coordinates(i, j)));
      }
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
  //

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

TEST(SettlementAlgorithmsTests, IsInside) {
  Point A(Coordinates(1, 1));
  Point B(Coordinates(1, 4));
  Point C(Coordinates(4, 1));

  // inside
  Point P1(Coordinates(2, 2));
  Point P2(Coordinates(4, 1));
  Point P3(Coordinates(2.5, 2.5));

  // outside
  Point P4(Coordinates(-2, 2));
  Point P5(Coordinates(10, 10));

  EXPECT_TRUE(isInside(P1, A, B, C));
  EXPECT_TRUE(isInside(P1, B, C, A));
  EXPECT_TRUE(isInside(P2, A, B, C));
  EXPECT_TRUE(isInside(P3, B, C, A));

  EXPECT_FALSE(isInside(P4, B, C, A));
  EXPECT_FALSE(isInside(P5, A, B, C));
  EXPECT_FALSE(isInside(Point(Coordinates(2.5, 2.6)), A, B, C));
}

TEST(SettlementAlgorithmsTests, SetHeight0) {
  Point A(Coordinates(1, 3));
  Point B(Coordinates(3, 1));
  Point T(Coordinates(2, 2));

  setHeight(&A, &B, &T);

  EXPECT_TRUE(T.getProperty(HEIGHT) == nullptr);
}

TEST(SettlementAlgorithmsTests, SetHeight1) {
  Point A(Coordinates(1, 3));
  Point B(Coordinates(3, 1));
  Point T(Coordinates(2, 2));
  Point T2(Coordinates(1, 3));
  Point T3(Coordinates(3, 1));

  A.addProperty(HEIGHT, "100");
  B.addProperty(HEIGHT, "200");
  setHeight(&A, &B, &T);
  setHeight(&A, &B, &T2);
  setHeight(&A, &B, &T3);

  EXPECT_TRUE(::atof(T.getProperty(HEIGHT)->c_str()) == 150.0);
  EXPECT_TRUE(::atof(T2.getProperty(HEIGHT)->c_str()) == 100.0);
  EXPECT_TRUE(::atof(T3.getProperty(HEIGHT)->c_str()) == 200.0);
}

TEST(SettlementAlgorithmsTests, SetHeight3) {
  Point A(Coordinates(1, 5));
  Point B(Coordinates(4, 5));
  Point T(Coordinates(2, 5));
  Point T2(Coordinates(3, 5));

  A.addProperty(HEIGHT, "180");
  B.addProperty(HEIGHT, "0");
  setHeight(&A, &B, &T);
  setHeight(&B, &A, &T2);

  EXPECT_TRUE(::atof(T.getProperty(HEIGHT)->c_str()) == 120.0);
  EXPECT_TRUE(::atof(T2.getProperty(HEIGHT)->c_str()) == 60.0);
}

// TEST(DEM1Fixture, SetHeight4) {
/*  for_each(DEM.begin(), DEM.end(),
           [](Point& p) { p.addProperty(HEIGHT, "100"); });

   Point A(Coordinates(0, 0));
   Point B(Coordinates(2.1, 2.9));
   Point C(Coordinates(2.9, 2.1));
   Point D(Coordinates(5, 5));

   setHeight(A, DEM, 5);
   setHeight(B, DEM, 5);
   setHeight(C, DEM, 5);
   setHeight(D, DEM, 5);

   EXPECT_TRUE(::atof(A.getProperty(HEIGHT)->c_str()) == 100.0);
   EXPECT_TRUE(::atof(B.getProperty(HEIGHT)->c_str()) == 100.0);
   EXPECT_TRUE(::atof(C.getProperty(HEIGHT)->c_str()) == 100.0);
   EXPECT_TRUE(D.getProperty(HEIGHT) == nullptr);*/
//}

/*более сложный случай получения высоты произвольной точки из матрицы
struct DEM2Fixture : public testing::Test {
  MultiPoint DEM;

  void SetUp() override {
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; j++)
        DEM.addObject(Point(Coordinates(i, j)));
  }

  void TearDown() override { DEM.clear(); }
};*/

#endif  // TST_SETTLEMENTSYSTEMALGORITHMS_H
