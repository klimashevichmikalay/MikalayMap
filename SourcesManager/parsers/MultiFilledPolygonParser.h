#ifndef MULTIFILLEDPOLYGONPARSER_H
#define MULTIFILLEDPOLYGONPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/FiguresTypes.h"
#include "../entities/LineString.h"
#include "../entities/MultiFilledPolygon.h"
#include "BaseFigureParser.h"
#include "FilledPolygonParser.h"
using namespace rapidjson;
using namespace std;

void mfpToJSON(MultiFilledPolygon _mfp, PrettyWriter<StringBuffer> &writer) {
  writer.StartObject();

  bfToJSON(_mfp, writer);

  writer.Key("scale");
  writer.Double(_mfp.getScale());

  writer.Key("polygons");
  writer.StartArray();

  vector<FilledPolygon> poligons = _mfp.getPolygons();

  for (size_t i = 0; i < poligons.size(); i++) {
    fpToJSON(poligons[i], writer);
  }
  writer.EndArray();
  writer.EndObject();
}

#endif  // MULTIFILLEDPOLYGON_H
