#include "Triangle.h"

using namespace Geometry;

void Triangle::addObject(const Point& p) {
  if (objectsSZ >= TRIANGLE_SZ) {
    throw std::logic_error(CANT_ADD_IN_TRIANGLE);
  }
  MultiFigure::addObject(p);
  ++objectsSZ;
}

unsigned Triangle::getSZ() const {
  return objectsSZ;
}

void Triangle::clear() {
  BaseFigure::clearPropetries();
  MultiFigure::clear();
  objectsSZ = 0;
}

Triangle::Triangle() : BaseFigure(TRIANGLE) {}
Triangle::Triangle(const std::string& name) : BaseFigure(name, TRIANGLE) {}
Triangle::~Triangle() {
  clear();
  objectsSZ = 0;
}

Triangle& Triangle::operator=(const Triangle& obj) {
  objectsSZ = 0;
  MultiFigure::operator=(obj);
  BaseFigure::operator=(obj);
  return *this;
}

bool Triangle::operator==(const Triangle& obj) {
  if (!BaseFigure::operator==(obj) || objectsSZ != obj.objectsSZ)
    return false;

  for (const auto& el : objects)
    if (!el || (!obj.isContains(*el)))
      return false;

  return true;
}
