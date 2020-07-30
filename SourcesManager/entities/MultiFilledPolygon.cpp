#include "MultiFilledPolygon.h"

#include <algorithm>
#include <vector>
/*
using namespace figureTypes;
using namespace std;

std::vector<FilledPolygon> MultiFilledPolygon::getPolygons() {
  return polygons;
}

bool MultiFilledPolygon::isContains(FilledPolygon _line) {
  for (size_t i = 0; i < polygons.size(); i++)
    if (polygons.at(i) == _line) return true;

  return false;
}

void MultiFilledPolygon::scalingByArea(float _area, bool _isShift) {
  float factor = sqrt(_area);
  scalingByFactor(factor, _isShift);
}

void MultiFilledPolygon::multCoordinates(float _factor) {
  Coordinates point;
  for (size_t i = 0; i < polygons.size(); i++) {
    vector<Coordinates> newPoints;
    for (size_t j = 0; j < polygons.at(i).getPoints().size(); j++) {
      {
        point = polygons.at(i).getPoints()[j];
        point *= _factor;
        newPoints.push_back(point);
      }
    }
    polygons.at(i).setPoints(newPoints);
  }
}

void MultiFilledPolygon::minusCoordinates(Coordinates _delta) {
  Coordinates point;
  for (size_t i = 0; i < polygons.size(); i++) {
    vector<Coordinates> newPoints;
    for (size_t j = 0; j < polygons.at(i).getPoints().size(); j++) {
      {
        point = polygons.at(i).getPoints()[j];
        point -= _delta;
        newPoints.push_back(point);
      }
    }
    polygons.at(i).setPoints(newPoints);
  }
}

void MultiFilledPolygon::scalingByFactor(float _scale, bool _isShift) {
  Coordinates avrOld = getAvrXY();
  multCoordinates(_scale);
  Coordinates avrCur = getAvrXY();
  avrCur -= avrOld;
  if (_isShift) minusCoordinates(avrCur);
  this->scale *= _scale;
}

Coordinates MultiFilledPolygon::getAvrXY() {
  Coordinates avr;
  int counter = 0;
  vector<Coordinates> coordinates;

  for (size_t i = 0; i < polygons.size(); i++) {
    counter += polygons.at(i).size();
    coordinates = polygons.at(i).getPoints();
    for (size_t j = 0; j < coordinates.size(); j++) {
      avr += coordinates.at(j);
    }
  }

  avr /= counter;

  return avr;
}

void MultiFilledPolygon::addPolygon(FilledPolygon _polygon) {
  polygons.push_back(_polygon);
}

void MultiFilledPolygon::clear() { polygons.clear(); }

MultiFilledPolygon::MultiFilledPolygon()
    : BaseFigure(MULTI_FILLED_POLYGON), Scale() {}

MultiFilledPolygon::MultiFilledPolygon(const char *_name)
    : BaseFigure(_name, MULTI_FILLED_POLYGON), Scale() {}

MultiFilledPolygon::MultiFilledPolygon(const std::string &_name)
    : BaseFigure(_name, MULTI_FILLED_POLYGON), Scale() {}

bool MultiFilledPolygon::operator==(MultiFilledPolygon obj) {
  if (type != obj.type) return false;

  if (polygons.size() != obj.polygons.size()) return false;

  if (getName().compare(obj.getName()) != 0) return false;

  for (size_t i = 0; i < obj.polygons.size(); i++)
    if (!isContains(obj.polygons.at(i))) return false;

  return true;
}
*/
