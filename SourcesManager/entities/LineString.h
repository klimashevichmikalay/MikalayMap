#ifndef LINESTRING_H
#define LINESTRING_H

#include <math.h>

#include <vector>

#include "BaseFigure.h"
#include "Coordinates.h"
#include "FiguresTypes.h"
#include "Scale.h"

class LineString : public BaseFigure, Scale {
 public:
  LineString();
  LineString(const std::string &_name);
  LineString(const char *_name);
  virtual ~LineString();

  void clear();
  void addCoordinate(Coordinates _crd);
  void scalingByArea(float _areaX);
  void scalingByFactor(float _scale);
  void move(Coordinates _delta);

  bool operator==(LineString obj);

 protected:
  Coordinates getAvrXY();
  std::vector<Coordinates> points;
};

#endif  // LINESTRING_H
