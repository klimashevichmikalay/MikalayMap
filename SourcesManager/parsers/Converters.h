#ifndef CONVERTERS_H
#define CONVERTERS_H

#include <string>

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

#endif  // CONVERTERS_H
