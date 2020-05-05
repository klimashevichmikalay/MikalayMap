#ifndef SCALE_H
#define SCALE_H

#include <vector>

#include "Coordinates.h"

class Scale {
 public:
  virtual void scalingByArea(float _area) = 0;
  virtual void scalingByFactor(float _scale) = 0;
  Scale() { scale = 1; }

 protected:
  float getScale() { return scale; }
  void setScale(float _scale) { scale = _scale; }

  void multCoordinates(std::vector<Coordinates> &points, float _factor);
  void minusCoordinates(std::vector<Coordinates> &points, Coordinates _delta);

  virtual Coordinates getAvrXY() = 0;

  float scale;
};

#endif  // SCALE_H
