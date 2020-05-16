#ifndef CORE_H
#define CORE_H

#include "ParsersCommand.h"
#include "SSConstants.h"

class Core {
 public:
  Core(string swampsPath, string lakesPath,
       string badSoilsPath) {  // string citiesPath) {
    swamps = pc.getParser(JSON)->getFilledPolygons(swampsPath);
    lakes = pc.getParser(JSON)->getFilledPolygons(lakesPath);
    badSoils = pc.getParser(JSON)->getFilledPolygons(badSoilsPath);
    //  cities = pc.getParser(JSON)->getMultiPoints(citiesPath);
  }

  vector<FilledPolygon> getLakes() { return lakes; };
  vector<FilledPolygon> getSwamps() { return swamps; }
  vector<FilledPolygon> getBadSoils() { return badSoils; };
  // vector<MultiPoint> getCities() { return cities; };

  ~Core() {
    lakes.clear();
    swamps.clear();
    badSoils.clear();
    //   cities.clear();
  }

  bool isBadPoint(Point _p) {
    FilledPolygon curPolygon;

    for (size_t i = 0; i < lakes.size(); i++) {
      curPolygon = lakes[i];
      if (curPolygon.isInPolygon(_p)) return true;
    }

    for (size_t i = 0; i < swamps.size(); i++) {
      curPolygon = swamps[i];
      if (curPolygon.isInPolygon(_p)) return true;
    }

    for (size_t i = 0; i < badSoils.size(); i++) {
      curPolygon = badSoils[i];
      if (curPolygon.isInPolygon(_p)) return true;
    }

    return false;
  }

 private:
  ParsersCommand pc;
  vector<FilledPolygon> lakes;
  vector<FilledPolygon> swamps;
  vector<FilledPolygon> badSoils;
  vector<MultiPoint> cities;
};

#endif  // CORE_H
