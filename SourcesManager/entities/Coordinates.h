#ifndef COORDINATES_H
#define COORDINATES_H

namespace Geometry {

class Coordinates {
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

  bool operator==(const Coordinates& obj) const;
  Coordinates& operator+=(const Coordinates& obj);
  Coordinates& operator-=(const Coordinates& obj);
  Coordinates& operator/=(double f);
  Coordinates& operator*=(double f);

 private:
  double X;
  double Y;
  static const double epsilon;
};
}  // namespace Geometry
#endif  // COORDINATES_H
