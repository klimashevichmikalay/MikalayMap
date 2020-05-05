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
};

#endif  // FILLEDPOLYGON_H
