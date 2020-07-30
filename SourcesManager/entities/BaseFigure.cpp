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

void BaseFigure::setType(const FigureType& newType) {
  if (newType < 0 || newType >= TYPES_SZ) {
    throw invalid_argument(
        "invalid argument: out of range in FigureType value");
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
  if (type != obj.type || properties.size() != obj.properties.size())
    return false;

  bool flag = false;
  for (const auto& el1 : properties) {
    for (const auto& el2 : obj.properties) {
      if (el1.first.compare(el2.first) == 0 && *(el1.second) == *(el2.second))
        flag = true;
    }

    if (!flag)
      return false;
  }
  return true;
}

BaseFigure& BaseFigure::operator=(const BaseFigure& obj) {
  assign(obj);
  return *this;
}

BaseFigure::BaseFigure() {
  setType(UNKNOWN);
}

BaseFigure::BaseFigure(const FigureType& newType) {
  setType(newType);
}

BaseFigure::BaseFigure(const string& name) {
  setType(UNKNOWN);
  addProperty(BaseFigure::NAME_PROP, name);
}

BaseFigure::BaseFigure(const string& name, const FigureType& type) {
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
  for (auto it = properties.begin(); it != properties.end(); it++)
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
  setType(obj.type);

  clearPropetries();
  for (auto it = obj.properties.begin(); it != obj.properties.end(); it++) {
    this->properties.insert({it->first, new string(*(it->second))});
  }
}
