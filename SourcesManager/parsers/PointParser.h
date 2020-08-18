#ifndef POINTSPARSER_H
#define POINTSPARSER_H

#include "../entities/Point.h"
#include "BaseFigureParser.h"
/*
void pointToJSON(Geometry::Point p,
                 rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) {
  writer.StartObject();
  bfToJSON(p, writer);

  writer.Key(SCALE_JSON);
  writer.Double(p.getScale());

  writer.Key(LOCATION_JSON);
  writer.StartArray();

  crdToJSON(*p.getLocation(), writer);

  writer.EndArray();
  writer.EndObject();
}

Geometry::Point jsonToPoint(string json) {
  Geometry::BaseFigure temp = jsonToBF(json);
  Geometry::Point result;
  result = temp;

  rapidjson::Document document;
  document.Parse(json.c_str());

  float scale = document["scale"].GetFloat();
  result.setScale(scale);

  const rapidjson::Value& attributes = document["location"];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value& attribute = *itr;
    result.setX(attribute["X"].GetFloat());
    result.setY(attribute["Y"].GetFloat());
  }
  return result;
}
*/
#endif  // GEOJSONCOMMAND_H
