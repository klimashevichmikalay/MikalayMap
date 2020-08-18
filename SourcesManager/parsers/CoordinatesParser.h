#ifndef COORDINATESPARSER_H
#define COORDINATESPARSER_H

#include <string>

#include "../RapidJson/rapidjson/prettywriter.h"
#include "../entities/Coordinates.h"
#include "../entities/FigureType.h"
using namespace std;

void crdToJSON(Geometry::Coordinates c,
               rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) {
  writer.StartObject();
  writer.Key("X");
  writer.Double(c.getX());
  writer.Key("Y");
  writer.Double(c.getY());
  writer.EndObject();
}

#endif  // COORDINATESPARSER_H
