#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Coordinates.h"
#include "vector"
/*
Coordinates *intersPointLineByOX(Coordinates point, Coordinates lineStart,
                                 Coordinates lineEnd) {
  float lowY =
      lineStart.getY() < lineEnd.getY() ? lineStart.getY() : lineEnd.getY();
  float upY =
      lineStart.getY() > lineEnd.getY() ? lineStart.getY() : lineEnd.getY();

  if (point.getY() > upY || point.getY() < lowY) return nullptr;

  point.setX(lineStart.getX());
  float proportion = fabs(point.getY() - lineStart.getY()) /
                     fabs(lineStart.getY() - lineEnd.getY());
  float _deltaX = proportion * (lineStart.getX() - lineEnd.getX());
  point.setX(point.getX() - _deltaX);

  Coordinates *result = new Coordinates;
  result->setX(point.getX());
  result->setY(point.getY());

  return result;
}

template <typename T>
bool isEqual(std::vector<T> &v1, std::vector<T> &v2) {
  return (v1.size() == v2.size() &&
          std::equal(v1.begin(), v1.end(), v2.begin()));
}*/

#endif  // ALGORITHMS_H
