#include "BaseFigure.h"

#include <string.h>

#include <algorithm>
#include <cctype>

using namespace std;
using namespace figureTypes;

string BaseFigure::toLower(string _str) {
  std::transform(_str.begin(), _str.end(), _str.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  return _str;
}

string BaseFigure::toLower(const char *_chars) {
  string result = "";

  for (size_t i = 0; i < strlen(_chars); i++)
    result.push_back((char)tolower(_chars[i]));

  return result;
}

FigureType BaseFigure::getType() { return type; }

void BaseFigure::setType(const FigureType &_type) {
  if (_type < 0 || _type >= TYPES_SZ) {
    throw invalid_argument(
        "invalid argument: out of range in FigureType value");
    return;
  }

  type = _type;
}

string BaseFigure::getName() { return getProperty(NAME_PROP); }

void BaseFigure::setName(const string &_name) { addProperty(NAME_PROP, _name); }

void BaseFigure::addInProperties(const std::string &_propName,
                                 const std::string &_prop) {
  propIterator = properties.find(_propName);

  if (propIterator != properties.end())
    propIterator->second = _prop;
  else
    properties.insert(pair<string, string>(_propName, _prop));
}

void BaseFigure::addProperty(const string &_propName, const string &_prop) {
  string addindProp = toLower(_prop);
  string addindPropName = toLower(_propName);
  addInProperties(addindPropName, addindProp);
}

void BaseFigure::addProperty(const string &_propName, const char *_prop) {
  string addindProp = toLower(_prop);
  string addindPropName = toLower(_propName);
  addInProperties(addindPropName, addindProp);
}

string BaseFigure::getProperty(const string &_propName) {
  string findingProp = toLower(_propName);

  propIterator = properties.find(findingProp);

  if (propIterator != properties.end()) return propIterator->second;

  return "";
}

void BaseFigure::delProperty(const string &_propName) {
  string delProp = toLower(_propName);
  properties.erase(delProp);
}

BaseFigure::BaseFigure() { type = UNKNOWN; }

BaseFigure::BaseFigure(const figureTypes::FigureType &_type) { type = _type; }

BaseFigure::BaseFigure(const char *_name) {
  type = UNKNOWN;
  addProperty(NAME_PROP, _name);
}

BaseFigure::BaseFigure(const string &_name) {
  type = UNKNOWN;
  addProperty(NAME_PROP, _name);
}

BaseFigure::BaseFigure(const char *_name, const FigureType &_type) {
  addProperty(NAME_PROP, _name);
  setType(_type);
}

BaseFigure::BaseFigure(const string &_name, const FigureType &_type) {
  addProperty(NAME_PROP, _name);
  setType(_type);
}
