#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../entities/EntitiesAll.h"
#include "BaseFigureParser.h"
#include "CoordinatesParser.h"
#include "FilledPolygonParser.h"
#include "LineStringParser.h"
#include "MultiFilledPolygonParser.h"
#include "MultiLineParser.h"
#include "MultiPointParser.h"
#include "ParsersConstants.h"
#include "PointParser.h"

class ICommand {
 public:
  virtual std::vector<MultiPoint> getMultiPoints(std::string _path) = 0;

  virtual std::vector<MultiLineString> getMultiLineStrings(
      std::string _path) = 0;

  virtual std::vector<MultiFilledPolygon> getMultiFilledPolygons(
      std::string _path) = 0;

  virtual std::vector<Point> getPoints(std::string _path) = 0;

  virtual std::vector<LineString> getLineStrings(std::string _path) = 0;

  virtual std::vector<FilledPolygon> getFilledPolygons(std::string _path) = 0;

  virtual void saveMultiPoints(std::vector<MultiPoint> points,
                               std::string _path) = 0;

  virtual void saveMultiLineStrings(std::vector<MultiLineString> line,
                                    std::string _path) = 0;

  virtual void saveMultiFilledPolygons(std::vector<MultiFilledPolygon> polygons,
                                       std::string _path) = 0;

  virtual void savePoints(std::vector<Point>, std::string _path) = 0;

  virtual void saveLineStrings(std::vector<LineString>, std::string _path) = 0;

  virtual void saveFilledPolygons(std::vector<FilledPolygon>,
                                  std::string _path) = 0;
};

#endif  // ABSTRACTFACTORY_H
