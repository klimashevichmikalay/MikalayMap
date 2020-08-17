#include "FilledPolygon.h"

using namespace Geometry;

bool FilledPolygon::operator==(const FilledPolygon& obj) {
  return MultiFigure::operator==(obj) && BaseFigure::operator==(obj);
}

void FilledPolygon::clear() {
  MultiFigure::clear();
  BaseFigure::clearPropetries();
}

FilledPolygon::FilledPolygon() : LineString() {
  setType(FILLED_POLYGON);
}

FilledPolygon::FilledPolygon(const std::string& _name) : LineString(_name) {
  setType(FILLED_POLYGON);
}

FilledPolygon::~FilledPolygon() {
  clear();
}

void FilledPolygon::operator=(const FilledPolygon& obj) {
  MultiFigure::operator=(obj);
  BaseFigure::operator=(obj);
}
