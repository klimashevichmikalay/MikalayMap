#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Coordinates.h"
#include "FigureType.h"
#include "LineString.h"
#include "Point.h"
/*using namespace std;
using namespace figureTypes;

class Triangle : public BaseFigure {
 public:
  vector<Point> getPoints() { return points; }

  void setPoints(vector<Point> ps) { this->points = ps; }

  void addCoordinate(Point _crd) {
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

    float A = area(points[0].getCoordinates(), points[1].getCoordinates(),
                   points[2].getCoordinates());
    float A1 =
        area(crd, points[1].getCoordinates(), points[2].getCoordinates());
    float A2 =
        area(points[0].getCoordinates(), crd, points[2].getCoordinates());
    float A3 =
        area(points[0].getCoordinates(), points[1].getCoordinates(), crd);

    return (A == A1 + A2 + A3);
  }

  bool isPointInVector(vector<Coordinates> v, Coordinates _p) {
    for (size_t i = 0; i < v.size(); i++) {
      if (v[i] == _p) return true;
    }
    return false;
  }

  bool operator==(Triangle t) {
    if (type != t.type) return false;

    if (points.size() != t.points.size()) return false;

    if (getName().compare(t.getName()) != 0) return false;

    vector<Coordinates> v;
    for (size_t i = 0; i < t.points.size(); i++) {
      v.push_back(t.points[i].getCoordinates());
    }

    for (size_t i = 0; i < points.size(); i++) {
      if (!isPointInVector(v, points[i].getCoordinates())) return false;
    }

    return true;
  }

  Triangle() : BaseFigure() { setType(TRIANGLE); }
  Triangle(const std::string &_name) : BaseFigure(_name) { setType(TRIANGLE); }
  Triangle(const char *_name) : BaseFigure(_name) { setType(TRIANGLE); }

  vector<Point> points;
};
*/
#endif  // TRIANGLE_H
