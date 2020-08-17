#ifndef MultiFigure_H
#define MultiFigure_H
#include <algorithm>
#include <vector>

#include "Coordinates.h"
#include "ICleaner.h"
#include "IScale.h"
#include "ISumCounter.h"

namespace Geometry {

template <typename PType, typename VType>
class MultiFigure : public IScale, public ISumCounter, ICleaner {
 public:
  using iterator = typename std::vector<PType>::iterator;
  using citerator = typename std::vector<PType>::const_iterator;

  iterator begin() { return objects.begin(); }
  iterator end() { return objects.end(); }
  citerator cbegin() { return objects.cbegin(); }
  citerator cend() { return objects.cend(); }

  iterator rbegin() { return objects.rbegin(); }
  iterator rend() { return objects.rend(); }
  citerator rcbegin() { return objects.rcbegin(); }
  citerator rcend() { return objects.rcend(); }

  void clear();

  virtual bool isContains(const VType& obj) const;
  virtual void addObject(const VType& obj);

  virtual void scalingByFactor(const double& factor, bool isshift);
  virtual void shift(const Coordinates& delta);
  virtual Coordinates countSum() const;
  virtual Coordinates getAvrXY();
  virtual void mult(double factor);
  virtual unsigned countObjs() const;

  virtual bool operator==(const MultiFigure& obj);
  virtual MultiFigure& operator=(const MultiFigure& obj);

  MultiFigure();
  MultiFigure(const MultiFigure& obj);
  virtual ~MultiFigure();

 protected:
  virtual void assing(const MultiFigure& obj);

  std::vector<PType> objects;
  Coordinates curSum;
  unsigned objsNum = 0;
};
}  // namespace Geometry

#include "MultiFigureImpl.h"

#endif  // MultiFigure_H
