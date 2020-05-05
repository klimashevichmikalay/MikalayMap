#include "Point.h"

using namespace figureTypes;

float Point::getX() { return location.getX(); }

float Point::getY() { return location.getY(); }

void Point::setX(float _X) { location.setX(_X); }

void Point::setY(float _Y) { location.setY(_Y); }

void Point::setCoordinates(Coordinates _location) { location = _location; }
Coordinates Point::getCoordinates() { return location; }

Point::Point() : BaseFigure(POINT) {}

Point::Point(const std::string &_name) : BaseFigure(_name, POINT) {}

Point::Point(const char *_name) : BaseFigure(_name, POINT) {}

Point::Point(Coordinates _location) : BaseFigure(POINT) {
  this->location = _location;
}

Point::Point(const std::string &_name, Coordinates _location)
    : BaseFigure(_name, POINT) {
  this->location = _location;
}

Point::Point(const char *_name, Coordinates _location)
    : BaseFigure(_name, POINT) {
  this->location = _location;
}

bool Point::operator==(Point obj) {
  if (getName().compare(obj.getName()) != 0) return false;

  if (!(getCoordinates() == obj.getCoordinates())) return false;

  if (getType() != obj.getType()) return false;

  return true;
}
