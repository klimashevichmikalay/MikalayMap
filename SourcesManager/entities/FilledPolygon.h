#ifndef FILLEDPOLYGON_H
#define FILLEDPOLYGON_H

#include "FiguresTypes.h"
#include "LineString.h"

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
};

#endif  // FILLEDPOLYGON_H
