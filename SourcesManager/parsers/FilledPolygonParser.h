/*#ifndef FILLEDPOLYGONPARSER_H
#define FILLEDPOLYGONPARSER_H

#include <string>

#include "../entities/FigureType.h"
#include "../entities/FilledPolygon.h"
#include "CoordinatesParser.h"
#include "LineStringParser.h"

using namespace std;

void fpToJSON(FilledPolygon _ls,
              rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer) {
  lineToJSON(_ls, writer);
}

FilledPolygon jsonToFP(string _json) {
  BaseFigure temp = jsonToBF(_json);
  FilledPolygon result;
  result.setProperties(temp.getProperties());

  rapidjson::Document document;
  document.Parse(_json.c_str());

  float scale = document["scale"].GetFloat();
  result.setScale(scale);

  const rapidjson::Value &attributes = document["points"];
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
*/
