#include "MultiFilledPolygon.h"

using namespace Geometry;

bool MultiFilledPolygon::operator==(const MultiFilledPolygon& obj) {
  return MultiFigure::operator==(obj) && BaseFigure::operator==(obj);
}

void MultiFilledPolygon::clear() {
  MultiFigure::clear();
  BaseFigure::clearPropetries();
}

MultiFilledPolygon::MultiFilledPolygon() {
  setType(MULTI_FILLED_POLYGON);
}

MultiFilledPolygon::MultiFilledPolygon(const std::string& _name)
    : BaseFigure(_name) {
  setType(MULTI_FILLED_POLYGON);
}

void MultiFilledPolygon::operator=(const MultiFilledPolygon& obj) {
  MultiFigure::operator=(obj);
  BaseFigure::operator=(obj);
}

MultiFilledPolygon::~MultiFilledPolygon() {
  clear();
}
