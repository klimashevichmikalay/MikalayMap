#ifndef BASEFIGUREPARSER_H
#define BASEFIGUREPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/BaseFigure.h"
#include "../entities/FiguresTypes.h"
#include "Converters.h"
#include "CoordinatesParser.h"
using namespace rapidjson;
using namespace std;

void bfToJSON(BaseFigure _bf, PrettyWriter<StringBuffer> &writer) {
  //  writer.StartObject();
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

#endif  // BASEFIGUREPARSER_H
