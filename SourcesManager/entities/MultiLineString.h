#ifndef MULTILINESTRING_H
#define MULTILINESTRING_H

#include "BaseFigure.h"
#include "LineString.h"
#include "MultiFigure.h"

namespace Geometry {

class MultiLineString : public BaseFigure,
                        public MultiFigure<LineString*, LineString> {
 public:
  void clear();

  MultiLineString();
  MultiLineString(const std::string& name);
  ~MultiLineString();

  bool operator==(const MultiLineString& obj);
  void operator=(const MultiLineString& obj);
};
}  // namespace Geometry
#endif  // MULTILINESTRING_H
