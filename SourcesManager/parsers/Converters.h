#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <string>
#include <unordered_map>

#include "../entities/FigureType.h"

using namespace std;

string enumToString(Geometry::FigureType type) {
  switch (type) {
    case Geometry::UNKNOWN: {
      return "UNKNOWN";
      break;
    }

    case Geometry::POINT: {
      return "POINT";
      break;
    }

    case Geometry::LINE_STR: {
      return "LINE_STR";
      break;
    }

    case Geometry::FILLED_POLYGON: {
      return "FILLED_POLYGON";
      break;
    }

    case Geometry::MULTI_POINT: {
      return "MULTI_POINT";
      break;
    }

    case Geometry::MULTI_LINE_STR: {
      return "MULTI_LINE_STR";
      break;
    }

    case Geometry::MULTI_FILLED_POLYGON: {
      return "MULTI_FILLED_POLYGON";
      break;
    }

    case Geometry::TRIANGLE: {
      return "TRIANGLE";
      break;
    }

    case Geometry::TYPES_SZ: {
      return "TYPES_SZ";
      break;
    }
  }

  return "UNKNOWN";
}

Geometry::FigureType strToEnum(string type) {
  if (type == "UNKNOWN")
    return Geometry::UNKNOWN;

  if (type == "POINT")
    return Geometry::POINT;

  if (type == "LINE_STR")
    return Geometry::LINE_STR;

  if (type == "FILLED_POLYGON")
    return Geometry::FILLED_POLYGON;

  if (type == "MULTI_POINT")
    return Geometry::MULTI_POINT;

  if (type == "MULTI_LINE_STR")
    return Geometry::MULTI_LINE_STR;

  if (type == "MULTI_FILLED_POLYGON")
    return Geometry::MULTI_FILLED_POLYGON;

  if (type == "TRIANGLE")
    return Geometry::TRIANGLE;

  return Geometry::UNKNOWN;
}

#endif  // CONVERTERS_H
