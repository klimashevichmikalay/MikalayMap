#ifndef SETTLEMENTCALCULATION_H
#define SETTLEMENTCALCULATION_H

#include <iostream>

#include "Algorithms.h"
#include "Core.h"
#include "PermutationsGenerator.h"
#include "SSAlgorithms.h"
#include "SSConstants.h"

using namespace std;
class SettlementCalculation {
 public:
  /////////////////////
  float width;
  float length;
  FilledPolygon frontZone;
  FilledPolygon radarZone;
  FilledPolygon targetCoverageZone;
  FilledPolygon AWZone;
  FilledPolygon object;
  vector<vector<Point>> coverResult;

  float getWidth() { return width; }
  float getLength() { return length; }
  FilledPolygon getFrontView() { return frontZone; }
  FilledPolygon getRadarView() { return radarZone; }
  FilledPolygon getTCZ() { return targetCoverageZone; }
  FilledPolygon getAWZone() { return AWZone; }
  FilledPolygon getProtectionObj() { return object; }
  vector<vector<Point>> getCoverResult() { return coverResult; }
  ////////////////////

  SettlementCalculation() { core = new Core(); }
  SettlementCalculation(string lakesPath,
                        string swampsPath,
                        string badSoilsPath,
                        string DEMpath,
                        size_t DEMLength) {  // lenght = heights points length
    core = new Core(swampsPath, lakesPath, badSoilsPath);
    core->setDEM(DEMpath, DEMLength);
  }

  vector<Point> getBestSettlement(FilledPolygon protectionObject,
                                  float antennaHeight,
                                  float maxAngle,
                                  float minAngle,
                                  float shifAngle,
                                  const float flightAltitude,
                                  const float potentialRange,
                                  const float AWRange,
                                  size_t radarsNum,
                                  float ZRKRange,
                                  size_t frontWidth,
                                  float impactAngle) {
    object = protectionObject;

    object.setProperties(protectionObject.getProperties());
    object.addProperty("view", "obj");
    object.setPoints(protectionObject.getPoints());
    AWZone = protectionObject.getAviationWeapons(AWRange);
    AWZone.addProperty("view", "AWZone");
    vector<vector<Point>> DEM = core->getDEM();

    float distanse2Points = fabs(DEM[0][0].getX() - DEM[0][1].getX());
    width = distanse2Points * DEM.size() - 1;
    length = distanse2Points * DEM[0].size() - 1;

    frontZone = getFrontZone(AWZone, frontWidth, impactAngle, length, width);

    frontZone.addProperty("view", "frontZone");

    radarZone = getRadarZone(frontZone, ZRKRange);
    radarZone.addProperty("view", "radarZone");
    targetCoverageZone = getTargetZone(frontZone, radarZone);
    targetCoverageZone.addProperty("view", "TCZ");

    MultiPoint targetCoverageZoneHeigth = getTZHeights(DEM, targetCoverageZone);
    MultiPoint radarZoneHeigth = getTZHeights(DEM, radarZone);

    size_t shift = frontWidth / (radarsNum / 3) / 4;
    shift /= distanse2Points;
    if (shift <= 0)
      shift = 1;

    triangles.clear();
    taggedPeaks.clear();

    Coordinates startInDEM = getCoordinateFromStr(
        radarZoneHeigth.getPoints()[0].getProperty("DEMXY"));

    genTriangles(radarZoneHeigth, shift, startInDEM);

    vector<Triangle> tr(getTriangles());

    vector<vector<int>> combs =
        generator.getPermutations(triangles.size(), radarsNum / 3);

    vector<vector<Point>> pointsComb = getPermutationsPoints(combs, triangles);

    int maxCoverage = 0;
    int curCov = 0;
    vector<Point> result;
    for (size_t i = 0; i < pointsComb.size(); i++) {
      vector<vector<Point>> DEMCopy(DEM);
      for (size_t j = 0; j < pointsComb[i].size(); j++) {
        Coordinates startInDEM =
            getCoordinateFromStr(pointsComb[i][j].getProperty("DEMXY"));

        findCoveragePoints(pointsComb[i][j], antennaHeight, maxAngle, minAngle,
                           shifAngle, DEMCopy, startInDEM, flightAltitude,
                           potentialRange, distanse2Points);
      }

      curCov = getVisiblePointsNum(DEMCopy, targetCoverageZone);

      if (curCov > maxCoverage) {
        maxCoverage = curCov;
        result.swap(pointsComb[i]);
        coverResult.swap(DEMCopy);
      }
    }
    return result;
  }

  int getVisiblePointsNum(vector<vector<Point>>& DEM,
                          FilledPolygon targetCoverageZone) {
    int counter = 0;

    for (size_t i = 0; i < DEM.size(); i++) {
      for (size_t j = 0; j < DEM[0].size(); j++) {
        if (DEM[i][j].getProperty("visible").compare("true") == 0 &&
            targetCoverageZone.isInPolygon(DEM[i][j]))
          counter++;
      }
    }
    return counter;
  }

  vector<vector<Point>> getPermutationsPoints(vector<vector<int>> combinations,
                                              vector<Triangle> trianglesCopy) {
    vector<vector<Point>> result;
    vector<vector<Triangle>> trs;

    for (size_t i = 0; i < combinations.size(); i++) {
      vector<Triangle> tv;
      for (size_t j = 0; j < combinations[i].size(); j++) {
        tv.push_back(trianglesCopy[combinations[i][j]]);
      }

      trs.push_back(tv);
    }

    for (size_t i = 0; i < trs.size(); i++) {
      result.push_back(getPointsFromTriangles(trs[i]));
    }

    return result;
  }

  vector<Point> getPointsFromTriangles(vector<Triangle> tv) {
    vector<Point> result;
    for (size_t i = 0; i < tv.size(); i++) {
      for (size_t j = 0; j < tv[i].getPoints().size(); j++) {
        if (!isPointInVector(result, tv[i].getPoints()[j])) {
          result.push_back(tv[i].getPoints()[j]);
        }
      }
    }

    return result;
  }

  // temp.addProperty("DEMXY", size_t2Str(j) + " " + size_t2Str(i));

  void genTriangles(MultiPoint TZHeights, size_t shift, Coordinates start) {
    Point* center = TZHeights.getFirstByPropetry(
        "DEMXY", size_t2Str(start.getX()) + " " + size_t2Str(start.getY()));

    Point* up = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX()) + " " + size_t2Str(start.getY() + shift));

    Point* down = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX()) + " " + size_t2Str(start.getY() - shift));

    Point* left = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX() - shift) + " " + size_t2Str(start.getY()));
    Point* right = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX() + shift) + " " + size_t2Str(start.getY()));

    taggedPeaks.push_back(*center);

    if (center && up && right && !core->isBadPoint(*up) &&
        !core->isBadPoint(*right) && !core->isBadPoint(*center)) {
      Triangle temp;
      temp.addCoordinate(*center);
      temp.addCoordinate(*up);
      temp.addCoordinate(*right);

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && down && right && !core->isBadPoint(*right) &&
        !core->isBadPoint(*down) && !core->isBadPoint(*center)) {
      Triangle temp;
      temp.addCoordinate(*center);
      temp.addCoordinate(*down);
      temp.addCoordinate(*right);

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && up && left && !core->isBadPoint(*up) &&
        !core->isBadPoint(*left) && !core->isBadPoint(*center)) {
      Triangle temp;
      temp.addCoordinate(*center);
      temp.addCoordinate(*up);
      temp.addCoordinate(*left);

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && down && left && !core->isBadPoint(*down) &&
        !core->isBadPoint(*left) && !core->isBadPoint(*center)) {
      Triangle temp;
      temp.addCoordinate(*center);
      temp.addCoordinate(*down);
      temp.addCoordinate(*left);

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (up && !isPointInVector(taggedPeaks, *up)) {
      genTriangles(TZHeights, shift,
                   getCoordinateFromStr(up->getProperty("DEMXY")));
    }

    if (down && !isPointInVector(taggedPeaks, *down)) {
      genTriangles(TZHeights, shift,
                   getCoordinateFromStr(down->getProperty("DEMXY")));
    }

    if (right && !isPointInVector(taggedPeaks, *right)) {
      genTriangles(TZHeights, shift,
                   getCoordinateFromStr(right->getProperty("DEMXY")));
    }

    if (left && !isPointInVector(taggedPeaks, *left)) {
      genTriangles(TZHeights, shift,
                   getCoordinateFromStr(left->getProperty("DEMXY")));
    }
  }

  vector<Triangle> getTriangles() { return triangles; }

  Core* getCore() { return core; }

 private:
  bool isHasThisTriangle(Triangle t) {
    for (size_t i = 0; i < triangles.size(); i++) {
      if (triangles[i] == t)
        return true;
    }
    return false;
  }

  bool isPointInVector(vector<Point> v, Point _p) {
    for (size_t i = 0; i < v.size(); i++) {
      if (v[i] == _p)
        return true;
    }
    return false;
  }

  Core* core;
  vector<Triangle> triangles;
  vector<Point> taggedPeaks;
  PermutationsGenerator generator;
};

#endif  // SETTLEMENTCALCULATION_H
