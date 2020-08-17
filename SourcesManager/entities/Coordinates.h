#ifndef COORDINATES_H
#define COORDINATES_H
#include "IScale.h"
#include "ISumCounter.h"

namespace Geometry {

class Coordinates : public IScale, public ISumCounter {
 public:
  double getX() const;
  double getY() const;

  double& refX();
  double& refY();

  void setX(double x);
  void setY(double y);

  double getProportionXY() const;

  virtual void shift(const Coordinates& delta) override;
  virtual void scalingByFactor(const double& factor, bool isShift) override;
  virtual void mult(double factor) override;
  virtual Coordinates countSum() const override;
  virtual unsigned countObjs() const override;

  Coordinates();
  Coordinates(double x, double y);
  ~Coordinates();

  bool operator==(const Coordinates& obj) const;
  Coordinates& operator+=(const Coordinates& obj);

  Coordinates& operator-=(const Coordinates& obj);
  Coordinates& operator/=(double f);
  Coordinates& operator*=(double f);
  Coordinates& operator=(const Coordinates& obj);

 private:
  double X;
  double Y;
  static const double epsilon;
};
}  // namespace Geometry
#endif  // COORDINATES_H
