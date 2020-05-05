#include "MultiPoint.h"

using namespace figureTypes;

std::vector<Point> MultiPoint::getPoints() { return points; }

bool MultiPoint::isContains(Point _point) {
  for (size_t i = 0; i < points.size(); i++)
    if (points.at(i) == _point) return true;

  return false;
}

void MultiPoint::addPoint(Point _point) { points.push_back(_point); }

void MultiPoint::clear() { points.clear(); }

MultiPoint::MultiPoint() : BaseFigure(POINT) {}

MultiPoint::MultiPoint(const char *_name) : BaseFigure(_name, POINT) {}

MultiPoint::MultiPoint(const std::string &_name) : BaseFigure(_name, POINT) {}

bool MultiPoint::operator==(MultiPoint obj) {
  if (type != obj.type) return false;

  if (points.size() != obj.points.size()) return false;

  if (getName().compare(obj.getName()) != 0) return false;
}
