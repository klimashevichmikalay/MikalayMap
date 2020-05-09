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

MultiLineString jsonToML(string _json) {
  BaseFigure temp = jsonToBF(_json);
  MultiLineString result;
  result.setProperties(temp.getProperties());

  Document document;
  document.Parse(_json.c_str());

  float scale = document["scale"].GetFloat();
  result.setScale(scale);

  const Value &attributes = document["lines"];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value &attribute = *itr;

    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    attribute.Accept(writer);
    std::string s = sb.GetString();

    LineString tp = jsonToLine(s);
    result.addLine(tp);
  }
  return result;
}

#endif  // MULTILINEPARSER_H
