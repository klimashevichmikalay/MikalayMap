#ifndef SCALE_H
#define SCALE_H

#include <vector>

namespace Geometry {

class Coordinates;

class IScale {
 public:
  double getScale() const;
  void setScale(double newScale);

  IScale();
  IScale(const IScale& obj);
  bool operator==(const IScale& obj) const;
  void operator=(const IScale& obj);
  virtual ~IScale(){};

  virtual void shift(const Coordinates& delta) = 0;
  virtual void scalingByFactor(const double& factor, bool isShift) = 0;
  virtual void mult(double factor) = 0;

  virtual Coordinates countSumXY() const = 0;

 protected:
  double scale;
};
}  // namespace Geometry
#endif  // SCALE_H
