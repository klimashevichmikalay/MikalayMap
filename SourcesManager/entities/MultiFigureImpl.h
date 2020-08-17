#ifndef MULTIFIGUREIMPL_H
#define MULTIFIGUREIMPL_H

#include "MultiFigure.h"

namespace Geometry {

template <typename PType, typename VType>
bool MultiFigure<PType, VType>::isContains(const VType& obj) const {
  for (const auto& el : objects)
    if (el && *el == obj)
      return true;
  return false;
}

template <typename PType, typename VType>
void MultiFigure<PType, VType>::addObject(const VType& obj) {
  curSum += obj.countSum();
  objsNum += obj.countObjs();

  PType toAdd = new VType(obj);
  objects.push_back(toAdd);
}

template <typename PType, typename VType>
void MultiFigure<PType, VType>::scalingByFactor(const double& factor,
                                                bool isshift) {
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

template <typename PType, typename VType>
void MultiFigure<PType, VType>::shift(const Coordinates& delta) {
  std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
    if (obj)
      obj->shift(delta);
  });
}

template <typename PType, typename VType>
Coordinates MultiFigure<PType, VType>::countSum() const {
  Coordinates result(0, 0);
  for_each(objects.begin(), objects.end(), [&](PType obj) {
    if (obj)
      result += obj->countSum();
  });
  return result;
}

template <typename PType, typename VType>
Coordinates MultiFigure<PType, VType>::getAvrXY() {
  Coordinates avr;
  avr.refX() = curSum.refX() / objsNum;
  avr.refY() = curSum.refY() / objsNum;
  return avr;
}

template <typename PType, typename VType>
void MultiFigure<PType, VType>::mult(double factor) {
  std::for_each(objects.begin(), objects.end(), [&](PType& obj) {
    if (obj)
      obj->mult(factor);
  });
}

template <typename PType, typename VType>
unsigned MultiFigure<PType, VType>::countObjs() const {
  int num = 0;
  for (const auto& el : objects)
    num += el->countObjs();

  return num;
}

template <typename PType, typename VType>
bool MultiFigure<PType, VType>::operator==(const MultiFigure& obj) {
  if (this == &obj)
    return true;

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

template <typename PType, typename VType>
void MultiFigure<PType, VType>::clear() {
  for_each(objects.begin(), objects.end(), [](PType& ptr) { delete ptr; });
  objects.clear();
  curSum *= 0;
  objsNum = 0;
}

template <typename PType, typename VType>
MultiFigure<PType, VType>::~MultiFigure() {
  clear();
}

template <typename PType, typename VType>
MultiFigure<PType, VType>& MultiFigure<PType, VType>::operator=(
    const MultiFigure& obj) {
  assing(obj);
  return *this;
}

template <typename PType, typename VType>
MultiFigure<PType, VType>::MultiFigure() {
  scale = 1;
}

template <typename PType, typename VType>
MultiFigure<PType, VType>::MultiFigure(const MultiFigure& obj) {
  assing(obj);
}

template <typename PType, typename VType>
void MultiFigure<PType, VType>::assing(const MultiFigure& obj) {
  if (this == &obj)
    return;

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

}  // namespace Geometry

#endif  // MULTIFIGUREIMPL_H
