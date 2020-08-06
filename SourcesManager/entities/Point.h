#ifndef POINT_H
#define POINT_H

#include "BaseFigure.h"
#include "Coordinates.h"
#include "ExceptionsMsgs.h"
#include "FigureType.h"
#include "IScale.h"
#include "SumCounter.h"

namespace Geometry {

class Point : public BaseFigure, public IScale {
 public:
  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);

  void setLocation(const Coordinates& newLocation);
  const Coordinates* getLocation() const;

  void shift(const Coordinates& delta);
  void scalingByFactor(const double& factor, bool shift);
  void mult(double factor);

  Point();
  Point(const std::string& name);
  Point(const Coordinates& location);
  Point(const std::string& name, const Coordinates& newLocation);

  Point(const Point& obj);

  ~Point();

  Point& operator=(const Point& obj);
  bool operator==(const Point& obj) const;

 protected:
  Coordinates countSumXY() const;

 private:
  bool checkLocation() const;
  void defInit();

  Coordinates* location = nullptr;
};
}  // namespace Geometry

#endif  // POINT_H
