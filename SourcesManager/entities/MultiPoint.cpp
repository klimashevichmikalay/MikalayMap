#include "MultiPoint.h"

using namespace Geometry;

MultiPoint::MultiPoint(const std::string& name)
    : BaseFigure(name, MULTI_POINT) {}

MultiPoint::MultiPoint() : BaseFigure(MULTI_POINT) {}

bool MultiPoint::operator==(const MultiPoint& obj) {
  return MultiFigure::operator==(obj) && BaseFigure::operator==(obj);
}

void MultiPoint::operator=(const MultiPoint& obj) {
  MultiFigure::operator=(obj);
  BaseFigure::operator=(obj);
}

void MultiPoint::clear() {
  clearPropetries();
  MultiFigure::clear();
}

MultiPoint::~MultiPoint() {
  clear();
}
