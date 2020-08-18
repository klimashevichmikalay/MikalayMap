#ifndef BASEFIGUREPARSER_H
#define BASEFIGUREPARSER_H

#include <string>
#include <vector>

#include "../RapidJson/rapidjson/document.h"
#include "../entities/BaseFigure.h"
#include "Converters.h"
#include "CoordinatesParser.h"
#include "ParsersConstants.h"
using namespace std;

void bfToJSON(Geometry::BaseFigure bf,
              rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) {
  writer.Key(TYPE_JSON);
  writer.String(enumToString(bf.getType()).c_str());
  writer.Key(PROPS_JSON);
  writer.StartArray();
  auto props = bf.getProperties();
  for (auto it = props.begin(); it != props.end(); ++it) {
    writer.StartObject();
    writer.Key(it->first.c_str());
    if (it->second)
      writer.String(it->second->c_str());
    else
      writer.String("");

    writer.EndObject();
  }
  writer.EndArray();
}

Geometry::BaseFigure jsonToBF(string json) {
  Geometry::BaseFigure result;
  rapidjson::Document document;
  document.Parse(json.c_str());

  string type = document[TYPE_JSON].GetString();
  result.setType(strToEnum(type));

  const rapidjson::Value& attributes = document[PROPS_JSON];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value& attribute = *itr;
    assert(attribute.IsObject());
    for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin();
         itr2 != attribute.MemberEnd(); ++itr2) {
      result.addProperty(itr2->name.GetString(), itr2->value.GetString());
    }
  }
  return result;
}

#endif  // BASEFIGUREPARSER_H
