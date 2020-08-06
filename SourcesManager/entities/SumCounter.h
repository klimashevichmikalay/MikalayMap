#ifndef SUMCOUNTER_H
#define SUMCOUNTER_H
#include "Coordinates.h"

namespace Geometry {
class SumCounter {
 public:
  SumCounter();

  bool operator==(const SumCounter& obj);
  void resetSum();

  void operator=(const SumCounter& obj);

 protected:
  Coordinates summXY;
};
}  // namespace Geometry
#endif  // SUMCOUNTER_H
