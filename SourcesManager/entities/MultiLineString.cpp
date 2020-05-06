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
  Coordinates point;
  for (size_t i = 0; i < lines.size(); i++) {
    vector<Coordinates> newPoints;
    for (size_t j = 0; j < lines.at(i).getPoints().size(); j++) {
      {
        point = lines.at(i).getPoints()[j];
        point *= _factor;
        newPoints.push_back(point);
      }
    }
    lines.at(i).setPoints(newPoints);
  }
}

void MultiLineString::minusCoordinates(Coordinates _delta) {
  Coordinates point;
  for (size_t i = 0; i < lines.size(); i++) {
    vector<Coordinates> newPoints;
    for (size_t j = 0; j < lines.at(i).getPoints().size(); j++) {
      {
        point = lines.at(i).getPoints()[j];
        point -= _delta;
        newPoints.push_back(point);
      }
    }
    lines.at(i).setPoints(newPoints);
  }
}

void MultiLineString::scalingByFactor(float _scale, bool _isShift) {
  Coordinates avrOld = getAvrXY();
  multCoordinates(_scale);
  Coordinates avrCur = getAvrXY();
  avrCur -= avrOld;
  if (_isShift) minusCoordinates(avrCur);
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
