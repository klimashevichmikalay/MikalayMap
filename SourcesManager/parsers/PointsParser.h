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

#endif  // GEOJSONCOMMAND_H
