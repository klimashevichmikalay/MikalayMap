#ifndef SCALE_H
#define SCALE_H

#include <vector>

#include "Coordinates.h"

namespace Geometry {

class IScale {
 public:
  double getScale() const;
  void setScale(double newScale);

  IScale();
  IScale(const IScale& obj);
  bool operator==(const IScale& obj) const;
  void operator=(const IScale& obj);

  virtual void shift(const Coordinates& delta) = 0;
  virtual void scalingByFactor(double factor) = 0;

 protected:
  double scale;
};
}  // namespace Geometry
#endif  // SCALE_H
