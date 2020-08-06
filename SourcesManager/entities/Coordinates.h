#ifndef COORDINATES_H
#define COORDINATES_H
#include "IScale.h"
namespace Geometry {

class Coordinates : public IScale {
 public:
  double getX() const;
  double getY() const;
  double& refX();
  double& refY();

  void setX(double x);
  void setY(double y);

  double getProportionXY() const;

  Coordinates();
  Coordinates(double x, double y);
  ~Coordinates() {}

  bool operator==(const Coordinates& obj) const;
  Coordinates& operator+=(const Coordinates& obj);

  Coordinates& operator-=(const Coordinates& obj);
  Coordinates& operator/=(double f);
  Coordinates& operator*=(double f);

  Coordinates& operator=(const Coordinates& obj) {
    X = obj.X;
    Y = obj.Y;
    return *this;
  }

  virtual void scalingByFactor(const double& factor, bool isShift) {
    scale *= factor;

    if (isShift)
      return;
    else
      *this *= factor;
  }

  void mult(double factor) { *this *= factor; }

  void shift(const Coordinates& delta) { *this += delta; }

  Coordinates countSumXY() const { return *this; }

 private:
  double X;
  double Y;
  static const double epsilon;
};
}  // namespace Geometry
#endif  // COORDINATES_H
