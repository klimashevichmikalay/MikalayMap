#ifndef BASEFIGURE_H
#define BASEFIGURE_H

#include <map>
#include <string>

#include "FigureType.h"

namespace Geometry {

class BaseFigure {
 public:
  FigureType getType() const;
  void setType(const FigureType& newType);

  const std::string* getName() const;
  void setName(const std::string& newName);

  void addProperty(const std::string& propName, const std::string& prop);
  void delProperty(const std::string& propName);
  const std::string* getProperty(const std::string& propName) const;

  bool operator==(const BaseFigure& obj) const;
  BaseFigure& operator=(const BaseFigure& obj);

  BaseFigure();
  BaseFigure(const FigureType& type);
  BaseFigure(const std::string& name);
  BaseFigure(const std::string& name, const FigureType& type);

  BaseFigure(const BaseFigure& obj);

  ~BaseFigure();

 protected:
  FigureType type;
  std::map<std::string, std::string*> properties;

 private:
  std::string toLower(const std::string& str) const;
  void clearPropetries();
  void assign(const BaseFigure& obj);
  static const std::string NAME_PROP;
};

}  // namespace Geometry
#endif  // BASEFIGURE_H
