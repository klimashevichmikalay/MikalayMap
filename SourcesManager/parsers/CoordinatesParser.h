#ifndef COORDINATESPARSER_H
#define COORDINATESPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/Coordinates.h"
#include "../entities/FiguresTypes.h"
using namespace std;

void crdToJSON(Coordinates _c,
               rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer) {
  // writer.StartArray();
  writer.StartObject();
  writer.Key("X");
  writer.Double(_c.getX());
  writer.Key("Y");
  writer.Double(_c.getY());
  writer.EndObject();
  //  writer.EndArray();
}

#endif  // COORDINATESPARSER_H
