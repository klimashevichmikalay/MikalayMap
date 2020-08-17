#include "Point.h"

using namespace Geometry;

double Point::getX() const {
  checkLocation();
  return location->getX();
}

double Point::getY() const {
  checkLocation();
  return location->getY();
}

void Point::setX(double x) {
  checkLocation();
  location->refX() = x;
}

void Point::setY(double y) {
  checkLocation();
  location->refY() = y;
}

void Point::setLocation(const Coordinates& newLocation) {
  if (location)
    delete location;

  location = new Coordinates;
  *location = newLocation;
}

void Point::shift(const Coordinates& delta) {
  if (location)
    *location += delta;
}

void Point::scalingByFactor(const double& factor, bool isShift) {
  scale *= factor;

  if (isShift && location)
    return;
  else
    *location *= factor;
}

void Point::mult(double factor) {
  if (location)
    *location *= factor;
}

const Coordinates* Point::getLocation() const {
  return location;
}

Point::Point() : BaseFigure(POINT), IScale() {
  defInit();
}

Point::Point(const std::string& name) : BaseFigure(name, POINT), IScale() {
  defInit();
}

Point::Point(const Coordinates& newLocation) : BaseFigure(POINT), IScale() {
  setLocation(newLocation);
}

Point::Point(const std::string& name, const Coordinates& newlocation)
    : BaseFigure(name, POINT), IScale() {
  setLocation(newlocation);
}

void Point::clear() {
  clearPropetries();
  if (location)
    delete location;
}

Point::Point(const Point& obj) : BaseFigure(obj), IScale(obj) {
  if (obj.location)
    setLocation(*obj.location);
  else
    location = nullptr;
}

Point::~Point() {
  if (location)
    delete location;

  clearPropetries();
}

Point& Point::operator=(const Point& obj) {
  BaseFigure::operator=(obj);
  IScale::operator=(obj);
  setLocation(*obj.location);

  return *this;
}

bool Point::operator==(const Point& obj) const {
  return *location == *obj.location && IScale::operator==(obj) &&
         BaseFigure::operator==(obj);
}

bool Point::checkLocation() const {
  if (location)
    return true;
  else
    throw std::logic_error(CANT_GET_VAL);
}

void Point::defInit() {
  location = new Coordinates(0, 0);
}

Coordinates Point::countSum() const {
  if (location)
    return *location;

  return Coordinates(0, 0);
}

unsigned Point::countObjs() const {
  return 1;
}
