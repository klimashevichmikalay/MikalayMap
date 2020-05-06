#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Coordinates.h"

Coordinates intersPointLineByOX(Coordinates point, Coordinates lineStart,
                                Coordinates lineEnd) {
  float lowY =
      lineStart.getY() < lineEnd.getY() ? lineStart.getY() : lineEnd.getY();
  float upY =
      lineStart.getY() > lineEnd.getY() ? lineStart.getY() : lineEnd.getY();

  if (point.getY() > upY || point.getY() < lowY)
    return Coordinates(-1000000, -1000000);

  point.setX(lineStart.getX());
  float proportion = fabs(point.getY() - lineStart.getY()) /
                     fabs(lineStart.getY() - lineEnd.getY());
  float _deltaX = proportion * (lineStart.getX() - lineEnd.getX());
  point.setX(point.getX() - _deltaX);

  return point;
}

#endif  // ALGORITHMS_H
