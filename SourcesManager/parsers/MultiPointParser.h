#ifndef MULTIPOINTPARSER_H
#define MULTIPOINTPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/FiguresTypes.h"
#include "../entities/MultiPoint.h"
#include "BaseFigureParser.h"
#include "PointParser.h"

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

MultiPoint jsonToMP(string _json) {
  BaseFigure temp = jsonToBF(_json);
  MultiPoint result;
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

    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    attribute.Accept(writer);
    std::string s = sb.GetString();

    Point tp = jsonToPoint(s);
    result.addPoint(tp);
  }
  return result;
}

#endif  // MULTIPOINTPARSER_H
