#ifndef LINESTRING_H
#define LINESTRING_H

#include <math.h>

#include <vector>

#include "BaseFigure.h"
#include "Coordinates.h"
#include "FiguresTypes.h"
#include "Scale.h"

class LineString : public BaseFigure, public Scale {
 public:
  LineString();
  LineString(const std::string &_name);
  LineString(const char *_name);
  virtual ~LineString();

  void clear();
  virtual void addCoordinate(Coordinates _crd);
  void scalingByArea(float _areaX, bool _isShift);
  void scalingByFactor(float _scale, bool _isShift);
  void move(Coordinates _delta);
  size_t size() { return points.size(); }
  bool operator==(LineString obj);
  std::vector<Coordinates> getPoints() { return points; }
  void setPoints(std::vector<Coordinates> _points) {
    std::swap(points, _points);
    ;
  }

 protected:
  std::vector<Coordinates> points;
  Coordinates getAvrXY();
};

#endif  // LINESTRING_H
