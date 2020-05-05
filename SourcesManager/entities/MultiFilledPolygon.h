#ifndef MULTIFILLEDPOLYGON_H
#define MULTIFILLEDPOLYGON_H

#include "FilledPolygon.h"

class MultiFilledPolygon : public BaseFigure, public Scale {
 public:
  std::vector<FilledPolygon> getPolygons();
  bool isContains(FilledPolygon _polygon);
  void addPolygon(FilledPolygon _polygon);
  void clear();

  MultiFilledPolygon();
  MultiFilledPolygon(const char *_name);
  MultiFilledPolygon(const std::string &_name);
  bool operator==(MultiFilledPolygon obj);

  Coordinates getAvrXY() { return Coordinates(0, 0); };
  void scalingByArea(float _area, bool _isShift);
  void scalingByFactor(float _scale, bool _isShift);

 private:
  std::vector<FilledPolygon> polygons;
};

#endif  // MULTIFILLEDPOLYGON_H
