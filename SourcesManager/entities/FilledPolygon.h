#ifndef FILLEDPOLYGON_H
#define FILLEDPOLYGON_H

#include <vector>

#include "FigureType.h"
#include "LineString.h"
#include "Point.h"

using namespace std;

namespace Geometry {

class FilledPolygon : public LineString {
 public:
  void clear();

  FilledPolygon();
  FilledPolygon(const std::string& name);
  ~FilledPolygon();

  bool operator==(const FilledPolygon& obj);
  void operator=(const FilledPolygon& obj);
};
}  // namespace Geometry
#endif  // FILLEDPOLYGON_H
