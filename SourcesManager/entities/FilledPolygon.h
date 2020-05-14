#ifndef FILLEDPOLYGON_H
#define FILLEDPOLYGON_H

#include "FiguresTypes.h"
#include "LineString.h"
#include "Point.h"

class FilledPolygon : public LineString {
 public:
  Coordinates getStart();
  Coordinates getEnd();

  FilledPolygon();
  FilledPolygon(const std::string &_name);
  FilledPolygon(const char *_name);

  void scalingByArea(float _areaX, bool _isShift) {
    LineString::scalingByArea(_areaX, _isShift);
  }
  void scalingByFactor(float _scale, bool _isShift) {
    LineString::scalingByFactor(_scale, _isShift);
  }

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

  bool isInPolygon(Coordinates _c) {
    Point _p(_c);
    return isInPolygon(_p);
  }

  bool isInPolygon(Point _p) {
    Coordinates outsidePoint(-25000, _p.getY());
    Coordinates *inters = nullptr;
    size_t counter = 0;
    for (size_t i = 1; i < points.size(); i++) {
      inters = intersPointLineByOX(outsidePoint, points[i - 1], points[i]);
      if (inters != nullptr && inters->getX() <= _p.getX() &&
          !(*inters == points[i - 1]) && !(*inters == points[i])) {
        counter++;
      }
    }

    inters = intersPointLineByOX(outsidePoint, getStart(), getEnd());
    if (inters != nullptr && inters->getX() <= _p.getX() &&
        !(*inters == getStart()) && !(*inters == getEnd())) {
      counter++;
    }

    return (counter % 2);
  }

  float getDistance(Coordinates a, Coordinates b) {
    float deltaX = fabs(a.getX() - b.getX());
    float deltaY = fabs(a.getY() - b.getY());

    return sqrt(deltaX * deltaX + deltaY * deltaY);
  }

  FilledPolygon getAviationWeapons(size_t _distance) {
    std::vector<Coordinates> oldPoints = points;

    while (getDistance(oldPoints[3], points[3]) <= _distance)
      scalingByFactor(1.05, true);

    FilledPolygon result;
    result.setPoints(points);
    this->setPoints(oldPoints);

    result.addProperty("VIEW", "AW");

    return result;
  }
};

#endif  // FILLEDPOLYGON_H
