#ifndef MULTIPOINT_H
#define MULTIPOINT_H
#include <vector>

#include "FiguresTypes.h"
#include "Point.h"
#include "Scale.h"

class MultiPoint : public BaseFigure, public Scale {
 public:
  std::vector<Point> getPoints();
  bool isContains(Point _point);
  void addPoint(Point _point);
  void clear();

  MultiPoint();
  MultiPoint(const char *_name);
  MultiPoint(const std::string &_name);
  bool operator==(MultiPoint obj);
  Coordinates getAvrXY();
  void multCoordinates(float _factor);
  void minusCoordinates(Coordinates _delta);
  void scalingByArea(float _area, bool _isShift);
  void scalingByFactor(float _scale, bool _isShift);

 private:
  std::vector<Point> points;
};

#endif  // MULTIPOINT_H
