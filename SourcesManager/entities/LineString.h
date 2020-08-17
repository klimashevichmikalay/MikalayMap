#ifndef LINESTRING_H
#define LINESTRING_H

#include <math.h>

#include "BaseFigure.h"
#include "MultiFigure.h"

namespace Geometry {

class LineString : public BaseFigure,
                   public MultiFigure<Coordinates*, Coordinates> {
 public:
  void clear();

  LineString();
  LineString(const std::string& name);
  ~LineString();

  bool operator==(const LineString& obj);
  LineString& operator=(const LineString& obj);
};
}  // namespace Geometry
#endif  // LINESTRING_H
