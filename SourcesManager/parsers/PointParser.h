#ifndef POINTSPARSER_H
#define POINTSPARSER_H

#include "../entities/Point.h"
#include "BaseFigureParser.h"
#include "CoordinatesParser.h"

void pointToJSON(Point _p, PrettyWriter<StringBuffer> &writer) {
  writer.StartObject();
  bfToJSON(_p, writer);

  writer.Key("scale");
  writer.Double(_p.getScale());

  writer.Key("location");
  writer.StartArray();

  crdToJSON(_p.getCoordinates(), writer);

  writer.EndArray();

  writer.EndObject();
}

Point jsonToPoint(string _json) {
  BaseFigure temp = jsonToBF(_json);
  Point result;
  result.setProperties(temp.getProperties());

  Document document;
  document.Parse(_json.c_str());

  float scale = document["scale"].GetFloat();
  result.setScale(scale);

  const Value &attributes = document["location"];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value &attribute = *itr;
    result.setX(attribute["X"].GetFloat());
    result.setY(attribute["Y"].GetFloat());
  }
  return result;
}

#endif  // GEOJSONCOMMAND_H
