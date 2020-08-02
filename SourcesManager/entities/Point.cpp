#include "Point.h"

using namespace Geometry;

double Point::getX() const {
  return location.getX();
}

double Point::getY() const {
  return location.getY();
}

void Point::setX(double x) {
  location.refX() = x;
}

void Point::setY(double y) {
  location.refY() = y;
}

void Point::setLocation(const Coordinates& newLocation) {
  location = newLocation;
}
const Coordinates& Point::getLocation() const {
  return location;
}

Point::Point() : BaseFigure(POINT), IScale() {}

Point::Point(const std::string& name) : BaseFigure(name, POINT), IScale() {}

Point::Point(const Coordinates& newLocation) : BaseFigure(POINT), IScale() {
  this->location = newLocation;
}

Point::Point(const std::string& _name, const Coordinates& newlocation)
    : BaseFigure(_name, POINT), IScale() {
  this->location = newlocation;
}

Point::Point(const Point& obj) : BaseFigure(obj), IScale(obj) {
  location = obj.location;
}

Point& Point::operator=(const Point& obj) {
  BaseFigure::operator=(obj);
  IScale::operator=(obj);
  location = obj.location;

  return *this;
}

bool Point::operator==(const Point& obj) const {
  return location == obj.location && IScale::operator==(obj) &&
         BaseFigure::operator==(obj);
}

void Point::shift(const Coordinates& delta) {
  location += delta;
}

void Point::scalingByFactor(double factor) {
  location *= factor;
  scale *= factor;
}
