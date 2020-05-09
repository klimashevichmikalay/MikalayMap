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

FilledPolygon jsonToFP(string _json) {
  BaseFigure temp = jsonToBF(_json);
  FilledPolygon result;
  result.setProperties(temp.getProperties());

  Document document;
  document.Parse(_json.c_str());

  float scale = document["scale"].GetFloat();
  result.setScale(scale);

  const Value &attributes = document["points"];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value &attribute = *itr;
    Coordinates temp;
    temp.setX(attribute["X"].GetFloat());
    temp.setY(attribute["Y"].GetFloat());
    result.addCoordinate(temp);
  }
  return result;
}

#endif  // FILLEDPOLYGONPARSER_H
