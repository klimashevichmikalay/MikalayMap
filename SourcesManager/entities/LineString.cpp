#include "LineString.h"

using namespace Geometry;

bool LineString::operator==(const LineString& obj) {
  return MultiFigure::operator==(obj) && BaseFigure::operator==(obj);
}

void LineString::clear() {
  MultiFigure::clear();
  BaseFigure::clearPropetries();
}

LineString::LineString(const std::string& _name) : BaseFigure(_name) {
  setType(LINE_STR);
}

LineString::LineString() {
  setType(LINE_STR);
}

LineString::~LineString() {
  clear();
}

LineString& LineString::operator=(const LineString& obj) {
  MultiFigure::operator=(obj);
  BaseFigure::operator=(obj);
  return *this;
}
