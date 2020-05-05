#include "MultiFilledPolygon.h"

using namespace figureTypes;

std::vector<FilledPolygon> MultiFilledPolygon::getPolygons() {
  return polygons;
}

bool MultiFilledPolygon::isContains(FilledPolygon _point) {
  for (size_t i = 0; i < polygons.size(); i++)
    if (polygons.at(i) == _point) return true;

  return false;
}

void MultiFilledPolygon::addPolygon(FilledPolygon _polygon) {
  polygons.push_back(_polygon);
}

void MultiFilledPolygon::scalingByArea(float _area, bool _isShift) {
  float factor = sqrt(_area);
  scalingByFactor(factor, _isShift);
}

void MultiFilledPolygon::scalingByFactor(float _scale, bool _isShift) {
  for (size_t i = 0; i < polygons.size(); i++)
    polygons.at(i).scalingByFactor(_scale, _isShift);
  setScale(scale * _scale);
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
