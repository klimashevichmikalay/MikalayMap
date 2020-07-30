/*#ifndef LINESTRINGPARSER_H
#define LINESTRINGPARSER_H

#include <string>

#include "../entities/LineString.h"
#include "BaseFigureParser.h"
#include "CoordinatesParser.h"

using namespace std;

void lineToJSON(LineString _ls,
                rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer) {
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

LineString jsonToLine(string _json) {
  BaseFigure temp = jsonToBF(_json);
  LineString result;
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

#endif  // LINESTRINGPARSER_H
*/
