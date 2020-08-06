#include "IScale.h"

using namespace Geometry;

double IScale::getScale() const {
  return scale;
}

void IScale::setScale(double newScale) {
  scale = newScale;
}

IScale::IScale() : scale(1.0) {}

IScale::IScale(const IScale& obj) {
  scale = obj.scale;
}

bool IScale::operator==(const IScale& obj) const {
  return scale == obj.scale;
}

void IScale::operator=(const IScale& obj) {
  scale = obj.scale;
}
