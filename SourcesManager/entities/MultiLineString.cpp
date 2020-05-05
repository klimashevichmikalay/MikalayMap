#include "MultiLineString.h"

#include <algorithm>
#include <vector>

using namespace figureTypes;
using namespace std;

std::vector<LineString> MultiLineString::getLines() { return lines; }

bool MultiLineString::isContains(LineString _line) {
  for (size_t i = 0; i < lines.size(); i++)
    if (lines.at(i) == _line) return true;

  return false;
}

void MultiLineString::scalingByArea(float _area, bool _isShift) {
  float factor = sqrt(_area);
  scalingByFactor(factor, _isShift);
}

void MultiLineString::multCoordinates(float _factor) {
  for (size_t i = 0; i < lines.size(); i++) {
    for (size_t j = 0; j < lines.at(i).getPoints().size(); j++) {
      lines.at(i).getPoints()[j].setX(lines.at(i).getPoints()[j].getX() *
                                      _factor);
    }
  }
}

void MultiLineString::minusCoordinates(Coordinates _delta) {
  for (size_t i = 0; i < lines.size(); i++) {
    for (size_t j = 0; j < lines.at(i).getPoints().size(); j++) {
      lines.at(i).getPoints()[j].setX(lines.at(i).getPoints()[j].getX() -
                                      _delta.getX());
      lines.at(i).getPoints()[j].setY(lines.at(i).getPoints()[j].getY() -
                                      _delta.getY());
    }
  }
}

void MultiLineString::scalingByFactor(float _scale, bool _isShift) {
  Coordinates avrOld = getAvrXY();
  multCoordinates(_scale);
  Coordinates avrCur = getAvrXY();
  Coordinates delta;
  avrCur -= avrOld;

  if (_isShift) minusCoordinates(delta);
  this->scale *= _scale;
}

Coordinates MultiLineString::getAvrXY() {
  Coordinates avr;
  int counter = 0;
  vector<Coordinates> coordinates;

  for (size_t i = 0; i < lines.size(); i++) {
    counter += lines.at(i).size();
    coordinates = lines.at(i).getPoints();
    for (size_t j = 0; j < coordinates.size(); j++) {
      avr += coordinates.at(j);
    }
  }

  avr /= counter;

  return avr;
}

void MultiLineString::addLine(LineString _line) { lines.push_back(_line); }

void MultiLineString::clear() { lines.clear(); }

MultiLineString::MultiLineString() : BaseFigure(MULTI_LINE_STR), Scale() {}

MultiLineString::MultiLineString(const char *_name)
    : BaseFigure(_name, MULTI_LINE_STR), Scale() {}

MultiLineString::MultiLineString(const std::string &_name)
    : BaseFigure(_name, MULTI_LINE_STR), Scale() {}

bool MultiLineString::operator==(MultiLineString obj) {
  if (type != obj.type) return false;

  if (lines.size() != obj.lines.size()) return false;

  if (getName().compare(obj.getName()) != 0) return false;

  for (size_t i = 0; i < obj.lines.size(); i++)
    if (!isContains(obj.lines.at(i))) return false;

  return true;
}
