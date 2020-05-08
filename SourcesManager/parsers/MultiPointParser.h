#ifndef MULTIPOINTPARSER_H
#define MULTIPOINTPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/FiguresTypes.h"
#include "../entities/MultiPoint.h"
#include "BaseFigureParser.h"
#include "PointsParser.h"

using namespace rapidjson;
using namespace std;

void mpToJSON(MultiPoint _mp, PrettyWriter<StringBuffer> &writer) {
  writer.StartObject();

  bfToJSON(_mp, writer);

  writer.Key("scale");
  writer.Double(_mp.getScale());

  writer.Key("points");
  writer.StartArray();

  vector<Point> points = _mp.getPoints();

  for (size_t i = 0; i < points.size(); i++) {
    pointToJSON(points[i], writer);
  }
  writer.EndArray();
  writer.EndObject();
}

#endif  // MULTIPOINTPARSER_H
