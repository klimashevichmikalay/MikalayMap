#ifndef MultiFigure_H
#define MultiFigure_H
#include <algorithm>
#include <vector>

#include "Coordinates.h"
#include "IScale.h"
#include "ISumCounter.h"

namespace Geometry {

template <typename PType, typename VType>
class MultiFigure : public IScale, public ISumCounter {
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
    curSum += obj.countSum();
    objsNum += obj.countObjs();

    PType toAdd = new VType(obj);
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

    curSum = countSum();

    if (isshift) {
      Coordinates delta = getAvrXY() -= oldAvr;
      delta.refX() = -delta.refX();
      delta.refY() = -delta.refY();
      shift(delta);
      curSum = countSum();
    }
  }

  void shift(const Coordinates& delta) {
    std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
      if (obj)
        obj->shift(delta);
    });
  }

  Coordinates countSum() const {
    Coordinates result(0, 0);
    for_each(objects.begin(), objects.end(), [&](PType obj) {
      if (obj)
        result += obj->countSum();
    });
    return result;
  }

  Coordinates getAvrXY() {
    Coordinates avr;
    avr.refX() = curSum.refX() / objsNum;
    avr.refY() = curSum.refY() / objsNum;
    return avr;
  }

  void mult(double factor) {
    std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
      if (obj)
        obj->mult(factor);
    });
  }

  unsigned countObjs() const {
    /* int sz = accumulate(objects.begin(), objects.end(), 0,
                      [](const PType& obj) { return obj->countSz(); });*/

    int num = 0;

    for (const auto& el : objects)
      num += el->countObjs();

    return num;
  }

  bool operator==(const MultiFigure& obj) {
    if (objects.size() != obj.objects.size())
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

  MultiFigure() { scale = 1; }

  MultiFigure(const MultiFigure& obj) { assing(obj); }

 protected:
  void clear() {
    for_each(objects.begin(), objects.end(), [](PType& ptr) { delete ptr; });
    objects.clear();
    curSum *= 0;
    objsNum = 0;
  }

  void assing(const MultiFigure& obj) {
    clear();
    IScale::operator=(obj);

    for (const auto& el : obj.objects) {
      if (el)
        addObject(*el);
      else {
        objects.push_back(nullptr);
      }
    }
  }

  std::vector<PType> objects;
  Coordinates curSum;
  unsigned objsNum = 0;
};

}  // namespace Geometry

//#include "MultiFigure.h"

/*using namespace Geometry;

template <typename PType, typename VType>
using iterator = typename std::vector<PType>::iterator;
template <typename PType, typename VType>
using citerator = typename std::vector<PType>::const_iterator;

template <typename PType, typename VType>
iterator<PType, VType> MultiFigure<PType, VType>::begin() {
  return objects.begin();
}
*/
// namespace Geometry
#endif  // MultiFigure_H
