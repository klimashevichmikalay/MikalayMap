#ifndef LINESTRINGPARSER_H
#define LINESTRINGPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/FiguresTypes.h"
#include "../entities/LineString.h"
#include "BaseFigureParser.h"
#include "CoordinatesParser.h"

using namespace rapidjson;
using namespace std;

void lineToJSON(LineString _ls, PrettyWriter<StringBuffer> &writer) {
  writer.StartObject();

  bfToJSON(_ls, writer);

  writer.Key("scale");
  writer.Double(_ls.getScale());

  writer.Key("points");
  writer.StartArray();

  vector<Coordinates> points = _ls.getPoints();

  for (std::vector<Coordinates>::const_iterator itr = points.begin();
       itr != points.end(); ++itr) {
    // writer.StartObject();
    crdToJSON(*itr, writer);
    // writer.EndObject();
  }
  writer.EndArray();

  writer.EndObject();
}

#endif  // LINESTRINGPARSER_H
