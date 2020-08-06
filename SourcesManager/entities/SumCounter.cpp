#include "SumCounter.h"

using namespace Geometry;

SumCounter::SumCounter() : summXY(Coordinates(0, 0)){};

bool SumCounter::operator==(const SumCounter& obj) {
  return summXY == obj.summXY;
}

void SumCounter::resetSum() {
  summXY.refX() = 0;
  summXY.refY() = 0;
}

void SumCounter::operator=(const SumCounter& obj) {
  summXY = obj.summXY;
}
