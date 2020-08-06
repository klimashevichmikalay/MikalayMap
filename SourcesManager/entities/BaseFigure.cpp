#include "BaseFigure.h"

#include <string.h>

#include <algorithm>
#include <cctype>

using namespace std;
using namespace Geometry;

const std::string BaseFigure::NAME_PROP = "name";

FigureType BaseFigure::getType() const {
  return type;
}

void BaseFigure::setType(FigureType newType) {
  if (newType < 0 || newType >= TYPES_SZ) {
    type = UNKNOWN;
    return;
  }
  type = newType;
}

const string* BaseFigure::getName() const {
  return getProperty(BaseFigure::NAME_PROP);
}

void BaseFigure::setName(const string& newName) {
  addProperty(BaseFigure::NAME_PROP, newName);
}

void BaseFigure::addProperty(const string& propName, const string& prop) {
  string addindProp = toLower(prop);
  string addindPropName = toLower(propName);

  auto propIterator = properties.find(addindPropName);

  if (propIterator != properties.end()) {
    delete propIterator->second;
    propIterator->second = new string(addindProp);
  } else
    properties.insert({addindPropName, new string(addindProp)});
}

const string* BaseFigure::getProperty(const string& propName) const {
  auto propIterator = properties.find(toLower(propName));

  if (propIterator != properties.end())
    return propIterator->second;

  return nullptr;
}

void BaseFigure::delProperty(const string& propName) {
  auto ptr = properties.find(propName);
  delete ptr->second;

  properties.erase(ptr);
}

bool BaseFigure::operator==(const BaseFigure& obj) const {
  if (this == &obj)
    return true;

  if (type != obj.type || properties.size() != obj.properties.size())
    return false;

  for (auto iter = properties.cbegin(); iter != properties.cend(); ++iter) {
    auto objIter = obj.properties.find(iter->first);
    if (objIter == obj.properties.end())
      return false;
    else if ((iter->second != nullptr &&
              iter->second->compare(*objIter->second)) ||
             (iter->second == nullptr && objIter->second != nullptr))
      return false;
  }
  return true;
}

bool BaseFigure::isHasProperty(const std::string& propName) {
  return getProperty(propName);
}

bool BaseFigure::isHasProperty(const std::string& propName,
                               const std::string& propValue) {
  const string* ptr = getProperty(propName);
  return ptr ? !(ptr->compare(propValue)) : false;
}

BaseFigure& BaseFigure::operator=(const BaseFigure& obj) {
  assign(obj);
  return *this;
}

BaseFigure::BaseFigure() {
  setType(UNKNOWN);
}

BaseFigure::BaseFigure(FigureType newType) {
  setType(newType);
}

BaseFigure::BaseFigure(const string& name) {
  setType(UNKNOWN);
  addProperty(BaseFigure::NAME_PROP, name);
}

BaseFigure::BaseFigure(const string& name, FigureType type) {
  addProperty(BaseFigure::NAME_PROP, name);
  setType(type);
}

BaseFigure::BaseFigure(const BaseFigure& obj) {
  assign(obj);
}

BaseFigure::~BaseFigure() {
  clearPropetries();
}

void BaseFigure::clearPropetries() {
  for (auto it = properties.begin(); it != properties.end(); ++it)
    delete it->second;

  properties.clear();
}

string BaseFigure::toLower(const string& str) const {
  string result(str);
  std::transform(result.begin(), result.end(), result.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  return result;
}

void BaseFigure::assign(const BaseFigure& obj) {
  if (this == &obj)
    return;

  setType(obj.type);
  clearPropetries();
  for (auto it = obj.properties.begin(); it != obj.properties.end(); ++it) {
    this->properties.insert({it->first, new string(*(it->second))});
  }
}
