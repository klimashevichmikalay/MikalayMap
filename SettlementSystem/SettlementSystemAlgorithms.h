#ifndef SETTLEMENTSYSTEMALGORITHMS_H
#define SETTLEMENTSYSTEMALGORITHMS_H

#include <cmath>

#include "MultiPoint.h"
#include "Point.h"
#include "SSConstants.h"

namespace SettlementAlgorithms {

/*возвращает точку с координатами, являющейся пересечением прямых,
  образуемых отрезами (A;B) & (A1; B1)*/
Geometry::Point* linesIntersection(Geometry::Point* A,
                                   Geometry::Point* B,
                                   Geometry::Point* C,
                                   Geometry::Point* D) {
  if (!A || !B || !C || !D)
    return nullptr;

  Geometry::Point* intersection = new Geometry::Point();

  /*Линия АВ представляется уравнением прямой: а1х + b1у = с1*/
  double a1 = B->getY() - A->getY();
  double b1 = A->getX() - B->getX();
  double c1 = a1 * (A->getX()) + b1 * (A->getY());

  /*Линия CD представляется уравнением прямой: а2х + b2у = с2*/
  double a2 = D->getY() - C->getY();
  double b2 = C->getX() - D->getX();
  double c2 = a2 * (C->getX()) + b2 * (C->getY());

  double determinant = a1 * b2 - a2 * b1;

  //Линии параллельны
  if (determinant == 0)
    return nullptr;

  intersection->setX((b2 * c1 - b1 * c2) / determinant);
  intersection->setY((a1 * c2 - a2 * c1) / determinant);

  return intersection;
}

struct DEMCell {
  const Geometry::Point* topLeft;
  const Geometry::Point* lowerLeft;
  const Geometry::Point* topRight;
  const Geometry::Point* lowerRight;
};

double findDistance(const Geometry::Point* p1, const Geometry::Point* p2) {
  return sqrt(pow((p1->getX() - p2->getX()), 2.0) +
              pow((p1->getY() - p2->getY()), 2.0));
}

bool chekDEMIndex(size_t col,
                  size_t row,
                  const Geometry::MultiPoint& DEM,
                  size_t colsNum) {
  return (col < colsNum) && (row < DEM.getSZ() / colsNum);
}

//предполагается, что матрица имеет квадратную или прямоугольную форму и что
//число столбцов и строк не менее 2-х
//также предполагается, что координаты высот положительные
DEMCell* getFramingCell(const Geometry::Point& p,
                        const Geometry::MultiPoint& DEM,
                        size_t colsNum) {
  if (DEM.getSZ() < CELL_POINTS_NUM)
    return nullptr;

  static double distance = findDistance(*DEM.cbegin(), *(DEM.cbegin() + 1));

  DEMCell* result = new DEMCell();

  unsigned col = p.getX() / distance;
  unsigned row = p.getY() / distance;

  if (!chekDEMIndex(col, row, DEM, colsNum) ||
      !chekDEMIndex(col + 1, row, DEM, colsNum) ||
      !chekDEMIndex(col + 1, row + 1, DEM, colsNum) ||
      !chekDEMIndex(col, row + 1, DEM, colsNum))
    return nullptr;

  result->topLeft = *(DEM.cbegin() + col + row * colsNum);
  result->topRight = *(DEM.cbegin() + (col + 1) + row * colsNum);
  result->lowerRight = *(DEM.cbegin() + (col + 1) + (row + 1) * colsNum);
  result->lowerLeft = *(DEM.cbegin() + (col) + (row + 1) * colsNum);

  return result;
}

}  // namespace SettlementAlgorithms

#endif  // SETTLEMENTSYSTEMALGORITHMS_H
