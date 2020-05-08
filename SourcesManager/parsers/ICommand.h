#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <string>
#include <vector>

#include "../entities/FiguresTypes.h"
#include "../entities/MultiFilledPolygon.h"
#include "../entities/MultiLineString.h"
#include "../entities/MultiPoint.h"

class ICommand {
 public:
  virtual MultiPoint getMultiPoint(std::string _path) = 0;
  virtual MultiLineString getMultiLineString(std::string _path) = 0;
  virtual MultiFilledPolygon getMultiFilledPolygon(std::string _path) = 0;
  virtual std::vector<Point> getPoints(std::string _path) = 0;
  virtual std::vector<LineString> getLineStrings(std::string _path) = 0;
  virtual std::vector<FilledPolygon> getFilledPolygons(std::string _path) = 0;
};

#endif  // ABSTRACTFACTORY_H
