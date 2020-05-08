#ifndef MULTILINEPARSER_H
#define MULTILINEPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/FiguresTypes.h"
#include "../entities/MultiLineString.h"
#include "LineStringParser.h"

using namespace rapidjson;
using namespace std;

void mlToJSON(MultiLineString _ls, PrettyWriter<StringBuffer> &writer) {
  writer.StartObject();

  bfToJSON(_ls, writer);

  writer.Key("scale");
  writer.Double(_ls.getScale());

  writer.Key("lines");
  writer.StartArray();

  vector<LineString> points = _ls.getLines();

  for (size_t i = 0; i < points.size(); i++) {
    lineToJSON(points[i], writer);
  }
  writer.EndArray();
  writer.EndObject();
}

#endif  // MULTILINEPARSER_H
