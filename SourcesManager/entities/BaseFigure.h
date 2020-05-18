#ifndef BASEFIGURE_H
#define BASEFIGURE_H

#include <map>
#include <string>

#include "EntitiesConstants.h"
#include "FiguresTypes.h"

class BaseFigure {
 public:
  figureTypes::FigureType getType();

  void addProperty(const std::string &_propName, const std::string &_prop);
  void addProperty(const std::string &_propName, const char *_prop);
  void delProperty(const std::string &_propName);
  std::string getProperty(const std::string &_propName);

  std::string getName();
  void setName(const std::string &_name);

  BaseFigure();
  BaseFigure(const figureTypes::FigureType &_type);
  BaseFigure(const char *_name);
  BaseFigure(const std::string &_name);
  BaseFigure(const char *_name, const figureTypes::FigureType &_type);
  BaseFigure(const std::string &_name, const figureTypes::FigureType &_type);

  std::map<std::string, std::string> getProperties() const {
    return properties;
  }
  void setType(const figureTypes::FigureType &_type);
  void setProperties(std::map<std::string, std::string> _props) {
    properties = _props;
  }

 protected:
  figureTypes::FigureType type;
  std::map<std::string, std::string> properties;

 private:
  std::map<std::string, std::string>::iterator propIterator;
  std::string toLower(std::string _str);
  std::string toLower(const char *_chars);
  void addInProperties(const std::string &_propName, const std::string &_prop);
};

#endif  // BASEFIGURE_H
