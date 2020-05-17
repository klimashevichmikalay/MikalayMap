#ifndef CORE_H
#define CORE_H

#include "ParsersCommand.h"
#include "SSConstants.h"

class Core {
 public:
  Core() {}
  Core(string swampsPath, string lakesPath, string badSoilsPath) {
    swamps = pc.getParser(JSON)->getFilledPolygons(swampsPath);
    lakes = pc.getParser(JSON)->getFilledPolygons(lakesPath);
    badSoils = pc.getParser(JSON)->getFilledPolygons(badSoilsPath);
  }

  vector<FilledPolygon> getLakes() { return lakes; };
  vector<FilledPolygon> getSwamps() { return swamps; }
  vector<FilledPolygon> getBadSoils() { return badSoils; };
  vector<vector<Point>> getDEM() { return DEM; }

  void setDEM(string DEMpath, size_t lenght) {
    vector<Point> points = pc.getParser(JSON)->getPoints(DEMpath);

    size_t pointsSZ = points.size();

    if (pointsSZ % lenght != 0) {
      throw std::logic_error(
          "setDEM exception: impossible to break array into matrix");
      return;
    }

    size_t width = pointsSZ / lenght;

    for (size_t i = 0; i < width; i++) {
      vector<Point> v;
      for (size_t j = lenght * i; j < lenght * (i + 1); j++) {
        v.push_back(points[j]);
      }
      DEM.push_back(v);
    }
  }

  ~Core() {
    lakes.clear();
    swamps.clear();
    badSoils.clear();
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
  vector<vector<Point>> DEM;
};

#endif  // CORE_H
