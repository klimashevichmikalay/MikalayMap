#ifndef MULTIFILLEDPOLYGON_H
#define MULTIFILLEDPOLYGON_H

#include "BaseFigure.h"
#include "FilledPolygon.h"

namespace Geometry {

class MultiFilledPolygon : public BaseFigure,
                           public MultiFigure<FilledPolygon*, FilledPolygon> {
 public:
  void clear();

  MultiFilledPolygon();
  MultiFilledPolygon(const std::string& name);
  ~MultiFilledPolygon();

  bool operator==(const MultiFilledPolygon& obj);
  void operator=(const MultiFilledPolygon& obj);
};
}  // namespace Geometry

#endif  // MULTIFILLEDPOLYGON_H
