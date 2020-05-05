#include "LineString.h"

#include <cmath>

using namespace figureTypes;
using namespace std;

void LineString::addCoordinate(Coordinates _crd) { points.push_back(_crd); }

void LineString::scalingByArea(float _areaX, bool _isShift) {
  float factor = sqrt(_areaX);
  scalingByFactor(factor, _isShift);
}

void LineString::scalingByFactor(float _scale, bool _isShift) {
  Coordinates avrOld = getAvrXY();
  multCoordinates(points, _scale);
  Coordinates avrCur = getAvrXY();
  Coordinates delta;
  delta.setX(avrCur.getX() - avrOld.getX());
  delta.setY(avrCur.getY() - avrOld.getY());

  if (_isShift) minusCoordinates(points, delta);
  this->scale *= _scale;
}

Coordinates LineString::getAvrXY() {
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

bool LineString::operator==(LineString obj) {
  if (getName().compare(obj.getName()) != 0) return false;

  if (points.size() != obj.points.size()) return false;

  for (size_t i = 0; i < points.size(); i++)
    if (!(points.at(i) == obj.points.at(i))) return false;

  return true;
}

void LineString::move(Coordinates _delta) {
  _delta.setX(-_delta.getX());
  _delta.setY(-_delta.getY());
  minusCoordinates(points, _delta);
}

void LineString::clear() { points.clear(); }

LineString::LineString() : BaseFigure(LINE_STR), Scale() {}

LineString::LineString(const std::string &_name)
    : BaseFigure(_name, LINE_STR), Scale() {}

LineString::LineString(const char *_name)
    : BaseFigure(_name, LINE_STR), Scale() {}

LineString::~LineString() {
  vector<Coordinates> empty;
  std::swap(points, empty);
}
