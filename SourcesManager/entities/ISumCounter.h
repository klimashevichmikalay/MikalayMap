#ifndef ISUMCOUNTER_H
#define ISUMCOUNTER_H

namespace Geometry {
class Coordinates;
class ISumCounter {
 public:
  ISumCounter() = default;
  virtual Coordinates countSum() const = 0;
  virtual unsigned countObjs() const = 0;
};
}  // namespace Geometry
#endif  // SUMCOUNTER_H
