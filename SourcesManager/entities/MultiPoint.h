#ifndef MULTIPOINT_H
#define MULTIPOINT_H
#include <vector>

#include "FigureType.h"
#include "MultiFigure.h"
#include "Point.h"

namespace Geometry {

class MultiPoint : public BaseFigure, public MultiFigure<Point*, Point> {
 public:
  void clear();

  MultiPoint();
  MultiPoint(const std::string& name);
  ~MultiPoint();

  void operator=(const MultiPoint& obj);
  bool operator==(const MultiPoint& obj);
};
}  // namespace Geometry
#endif  // MULTIPOINT_H
