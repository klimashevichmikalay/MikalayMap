#ifndef BASEFIGUREPARSER_H
#define BASEFIGUREPARSER_H

#include <string>
#include <vector>

#include "../RapidJson/rapidjson/document.h"
#include "../RapidJson/rapidjson/prettywriter.h"
#include "../RapidJson/rapidjson/reader.h"
#include "../entities/BaseFigure.h"
#include "../entities/FiguresTypes.h"
#include "Converters.h"
#include "CoordinatesParser.h"
using namespace rapidjson;
using namespace std;

void bfToJSON(BaseFigure _bf, PrettyWriter<StringBuffer> &writer) {
  // writer.StartObject();
  writer.Key("type");
  writer.String(enumToString(_bf.getType()).c_str());
  writer.Key(("properties"));
  writer.StartArray();
  std::map<std::string, std::string> props = _bf.getProperties();
  for (map<std::string, std::string>::const_iterator it = props.begin();
       it != props.end(); ++it) {
    writer.StartObject();
    writer.Key(it->first.c_str());
    writer.String(it->second.c_str());
    writer.EndObject();
  }
  writer.EndArray();

  //  writer.EndObject();
}

BaseFigure jsonToBF(string _json) {
  BaseFigure result;
  Document document;
  document.Parse(_json.c_str());

  string type = document["type"].GetString();
  result.setType(strToEnum(type));

  const Value &attributes = document["properties"];
  assert(attributes.IsArray());
  for (rapidjson::Value::ConstValueIterator itr = attributes.Begin();
       itr != attributes.End(); ++itr) {
    const rapidjson::Value &attribute = *itr;
    assert(attribute.IsObject());  // each attribute is an object
    for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin();
         itr2 != attribute.MemberEnd(); ++itr2) {
      result.addProperty(itr2->name.GetString(), itr2->value.GetString());
    }
  }
  return result;
}

#endif  // BASEFIGUREPARSER_H
