#include "MultiLineString.h"

using namespace Geometry;

bool MultiLineString::operator==(const MultiLineString& obj) {
  return MultiFigure::operator==(obj) && BaseFigure::operator==(obj);
}

void MultiLineString::clear() {
  MultiFigure::clear();
  BaseFigure::clearPropetries();
}

MultiLineString::MultiLineString() {
  setType(MULTI_LINE_STR);
}

MultiLineString::MultiLineString(const std::string& _name) : BaseFigure(_name) {
  setType(MULTI_LINE_STR);
}

void MultiLineString::operator=(const MultiLineString& obj) {
  MultiFigure::operator=(obj);
  BaseFigure::operator=(obj);
}

MultiLineString::~MultiLineString() {
  clear();
}
