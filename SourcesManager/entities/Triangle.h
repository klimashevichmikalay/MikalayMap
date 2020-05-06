#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Coordinates.h"
#include "FiguresTypes.h"
#include "LineString.h"

using namespace std;
using namespace figureTypes;

class Triangle : public LineString {
 public:
  void addCoordinate(Coordinates _crd) override {
    if (points.size() > 2) {
      throw std::logic_error("triangle must have three points");
    }
    points.push_back(_crd);
  }

  float area(Coordinates a, Coordinates b, Coordinates c) {
    return fabs((a.getX() * (b.getY() - c.getY()) +
                 b.getX() * (c.getY() - a.getY()) +
                 c.getX() * (a.getY() - b.getY())) /
                2.0);
  }

  bool isInside(Coordinates crd) {
    if (points.size() != 3) {
      throw std::logic_error("can not find area if has not 3 points");
    }

    float A = area(points[0], points[1], points[2]);
    float A1 = area(crd, points[1], points[2]);
    float A2 = area(points[0], crd, points[2]);
    float A3 = area(points[0], points[1], crd);

    return (A == A1 + A2 + A3);
  }

  Triangle() : LineString() { setType(TRIANGLE); }
  Triangle(const std::string &_name) : LineString(_name) { setType(TRIANGLE); }
  Triangle(const char *_name) : LineString(_name) { setType(TRIANGLE); }
};

#endif  // TRIANGLE_H
