#ifndef LINESTRING_H
#define LINESTRING_H

#include <math.h>

#include "BaseFigure.h"
#include "MultiFigure.h"

namespace Geometry {

class LineString : public BaseFigure,
                   public MultiFigure<Coordinates*, Coordinates> {
 public:
  LineString() : BaseFigure(LINE_STR) {}
  LineString(const std::string& name) : BaseFigure(name, LINE_STR) {}
  virtual ~LineString() {}
  void clear() { MultiFigure::clear(); }

  bool operator==(LineString obj) {
    return MultiFigure::operator==(obj) && BaseFigure::operator==(obj);
  }
};

}  // namespace Geometry
#endif  // LINESTRING_H
