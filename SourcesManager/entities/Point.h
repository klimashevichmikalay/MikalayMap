#ifndef POINT_H
#define POINT_H

#include "BaseFigure.h"
#include "Coordinates.h"
#include "FigureType.h"
#include "IScale.h"

namespace Geometry {

class Point : public BaseFigure, public IScale {
 public:
  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);

  void setLocation(const Coordinates& newLocation);
  const Coordinates& getLocation() const;

  Point();
  Point(const std::string& name);
  Point(const Coordinates& location);
  Point(const std::string& name, const Coordinates& newLocation);

  Point(const Point& obj);

  Point& operator=(const Point& obj);
  bool operator==(const Point& obj) const;

  void shift(const Coordinates& delta);
  void scalingByFactor(double factor);

 private:
  Coordinates location;
};
}  // namespace Geometry

#endif  // POINT_H
