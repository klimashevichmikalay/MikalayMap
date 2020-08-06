#ifndef MultiFigure_H
#define MultiFigure_H
#include <algorithm>
#include <vector>

#include "IScale.h"
#include "SumCounter.h"
namespace Geometry {

template <typename PType, typename VType>
class MultiFigure : public IScale, public SumCounter {
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

  bool isContains(const VType& obj) {
    for (const auto& el : objects)
      if (el && *el == obj)
        return true;
    return false;
  }

  void addObject(const VType& obj) {
    summXY += obj.countSumXY();
    PType toAdd = new VType;
    *toAdd = obj;
    objects.push_back(toAdd);
  }

  void scalingByFactor(const double& factor, bool isshift) {
    scale *= factor;
    if (objects.size() == 0)
      return;

    Coordinates oldAvr = getAvrXY();
    std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
      if (obj)
        obj->mult(factor);
    });

    if (isshift) {
      Coordinates curAvr = getAvrXY();
      curAvr -= oldAvr;
      curAvr.refX() = -curAvr.refX();
      curAvr.refY() = -curAvr.refY();
      shift(curAvr);
    }
  }

  void shift(const Coordinates& delta) {
    std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
      if (obj)
        *obj += delta;
    });
  }

  Coordinates countSumXY() const { return summXY; }

  Coordinates getAvrXY() {
    Coordinates avr;
    avr.refX() = summXY.refX() / objects.size();
    avr.refY() = summXY.refY() / objects.size();
    return avr;
  }

  void mult(double factor) {
    std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
      if (obj)
        obj->mult(factor);
    });
  }

  bool operator==(const MultiFigure& obj) {
    if (objects.size() != obj.objects.size() || !SumCounter::operator==(obj))
      return false;

    auto objIter = obj.objects.cbegin();
    auto thisIter = objects.cbegin();
    for (; thisIter != objects.cend(); objIter++, thisIter++) {
      if (!*objIter && !*thisIter)
        continue;
      else {
        if ((*objIter && !*thisIter) || (!*objIter && *thisIter) ||
            !(**objIter == **thisIter))
          return false;
      }
    }
    return true;
  }

  virtual ~MultiFigure() { clear(); }

  MultiFigure& operator=(const MultiFigure& obj) {
    assing(obj);
    return *this;
  }

  MultiFigure() : SumCounter(), IScale() {}

  MultiFigure(const MultiFigure& obj) { assing(obj); }

 protected:
  void clear() {
    for_each(objects.begin(), objects.end(), [](PType& ptr) { delete ptr; });
    objects.clear();
    resetSum();
  }

  void assing(const MultiFigure& obj) {
    clear();
    IScale::operator=(obj);
    SumCounter::operator=(obj);

    for (const auto& el : obj.objects) {
      if (el)
        addObject(*el);
      else {
        objects.push_back(nullptr);
      }
    }
  }

  std::vector<PType> objects;
};
}  // namespace Geometry
#endif  // MultiFigure_H
