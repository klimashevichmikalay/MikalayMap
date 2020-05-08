#ifndef FILLEDPOLYGONPARSER_H
#define FILLEDPOLYGONPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/FiguresTypes.h"
#include "../entities/FilledPolygon.h"
#include "CoordinatesParser.h"
#include "LineStringParser.h"

using namespace rapidjson;
using namespace std;

void fpToJSON(FilledPolygon _ls, PrettyWriter<StringBuffer> &writer) {
  lineToJSON(_ls, writer);
}

#endif  // FILLEDPOLYGONPARSER_H
