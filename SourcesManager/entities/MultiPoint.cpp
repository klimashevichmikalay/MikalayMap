#include "MultiPoint.h"

#include <algorithm>

using namespace figureTypes;
using namespace std;

std::vector<Point> MultiPoint::getPoints() { return points; }

bool MultiPoint::isContains(Point _point) {
  for (size_t i = 0; i < points.size(); i++)
    if (points.at(i) == _point) return true;

  return false;
}

void MultiPoint::scalingByArea(float _area, bool _isShift) {
  float factor = sqrt(_area);
  scalingByFactor(factor, _isShift);
}

void MultiPoint::multCoordinates(float _factor) {
  for (auto it = points.begin(); it != points.end(); ++it) {
    it->setX(it->getX() * _factor);
    it->setY(it->getY() * _factor);
  }
}

void MultiPoint::minusCoordinates(Coordinates _delta) {
  for (auto it = points.begin(); it != points.end(); ++it) {
    it->setX(it->getX() - _delta.getX());
    it->setY(it->getY() - _delta.getY());
  }
}

void MultiPoint::scalingByFactor(float _scale, bool _isShift) {
  Coordinates avrOld = getAvrXY();
  multCoordinates(_scale);
  Coordinates avrCur = getAvrXY();
  Coordinates delta;
  delta.setX(avrCur.getX() - avrOld.getX());
  delta.setY(avrCur.getY() - avrOld.getY());
  if (_isShift) minusCoordinates(delta);
  this->scale *= _scale;
}

Coordinates MultiPoint::getAvrXY() {
  Coordinates avr;

  for (auto it = points.begin(); it != points.end(); ++it) {
    avr.setX(avr.getX() + it->getX());
    avr.setY(avr.getY() + it->getY());
  }

  size_t pSz = points.size();

  avr.setX(avr.getX() / pSz);
  avr.setY(avr.getY() / pSz);

  return avr;
}

void MultiPoint::addPoint(Point _point) { points.push_back(_point); }

void MultiPoint::clear() { points.clear(); }

MultiPoint::MultiPoint() : BaseFigure(MULTI_POINT), Scale() {}

MultiPoint::MultiPoint(const char *_name)
    : BaseFigure(_name, MULTI_POINT), Scale() {}

MultiPoint::MultiPoint(const std::string &_name)
    : BaseFigure(_name, MULTI_POINT), Scale() {}

bool MultiPoint::operator==(MultiPoint obj) {
  if (type != obj.type) return false;

  if (points.size() != obj.points.size()) return false;

  if (getName().compare(obj.getName()) != 0) return false;

  for (size_t i = 0; i < obj.points.size(); i++)
    if (!isContains(obj.points.at(i))) return false;

  return true;
}
