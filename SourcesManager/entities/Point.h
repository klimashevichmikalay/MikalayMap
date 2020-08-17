#ifndef POINT_H
#define POINT_H

#include "BaseFigure.h"
#include "Coordinates.h"
#include "ExceptionsMsgs.h"
#include "ICleaner.h"
#include "IScale.h"
#include "ISumCounter.h"

namespace Geometry {

class Point : public BaseFigure,
              public IScale,
              public ISumCounter,
              public ICleaner {
 public:
  void clear();

  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);

  void setLocation(const Coordinates& newLocation);
  const Coordinates* getLocation() const;

  void shift(const Coordinates& delta) override;
  void scalingByFactor(const double& factor, bool shift) override;
  void mult(double factor) override;

  Coordinates countSum() const override;
  unsigned countObjs() const override;

  Point();
  Point(const std::string& name);
  Point(const Coordinates& location);
  Point(const std::string& name, const Coordinates& newLocation);
  Point(const Point& obj);
  ~Point();

  Point& operator=(const Point& obj);
  bool operator==(const Point& obj) const;

 private:
  bool checkLocation() const;
  void defInit();

  Coordinates* location = nullptr;
};
}  // namespace Geometry

#endif  // POINT_H
