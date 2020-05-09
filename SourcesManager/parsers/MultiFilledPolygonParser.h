#ifndef MULTIFILLEDPOLYGONPARSER_H
#define MULTIFILLEDPOLYGONPARSER_H

#include <string>

#include "../entities/LineString.h"
#include "../entities/MultiFilledPolygon.h"
#include "BaseFigureParser.h"
#include "FilledPolygonParser.h"

using namespace std;

void mfpToJSON(MultiFilledPolygon _mfp,
               rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer) {
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

MultiFilledPolygon jsonToMFP(string _json) {
  BaseFigure temp = jsonToBF(_json);
  MultiFilledPolygon result;
  result.setProperties(temp.getProperties());

  rapidjson::Document document;
  document.Parse(_json.c_str());

  float scale = document["scale"].GetFloat();
  result.setScale(scale);

  const rapidjson::Value &attributes = document["polygons"];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value &attribute = *itr;

    rapidjson::StringBuffer sb;
    rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
    attribute.Accept(writer);
    std::string s = sb.GetString();

    FilledPolygon fp = jsonToFP(s);
    result.addPolygon(fp);
  }
  return result;
}

#endif  // MULTIFILLEDPOLYGON_H
