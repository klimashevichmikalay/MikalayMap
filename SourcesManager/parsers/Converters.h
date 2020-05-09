#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <string>
#include <unordered_map>

#include "../entities/FiguresTypes.h"

using namespace std;
using namespace figureTypes;

string enumToString(FigureType _type) {
  switch (_type) {
    case UNKNOWN: {
      return "UNKNOWN";
      break;
    }

    case POINT: {
      return "POINT";
      break;
    }

    case LINE_STR: {
      return "LINE_STR";
      break;
    }

    case FILLED_POLYGON: {
      return "FILLED_POLYGON";
      break;
    }

    case MULTI_POINT: {
      return "MULTI_POINT";
      break;
    }

    case MULTI_LINE_STR: {
      return "MULTI_LINE_STR";
      break;
    }

    case MULTI_FILLED_POLYGON: {
      return "MULTI_FILLED_POLYGON";
      break;
    }

    case TRIANGLE: {
      return "TRIANGLE";
      break;
    }

    case TYPES_SZ: {
      return "TYPES_SZ";
      break;
    }
  }

  return "UNKNOWN";
}

FigureType strToEnum(string _type) {
  if (_type == "UNKNOWN") return UNKNOWN;

  if (_type == "POINT") return POINT;

  if (_type == "LINE_STR") return LINE_STR;

  if (_type == "FILLED_POLYGON") return FILLED_POLYGON;

  if (_type == "MULTI_POINT") return MULTI_POINT;

  if (_type == "MULTI_LINE_STR") return MULTI_LINE_STR;

  if (_type == "MULTI_FILLED_POLYGON") return MULTI_FILLED_POLYGON;

  if (_type == "TRIANGLE") return TRIANGLE;

  return UNKNOWN;
}

#endif  // CONVERTERS_H
