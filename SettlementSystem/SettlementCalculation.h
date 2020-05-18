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
  SettlementCalculation() { core = new Core(); }
  SettlementCalculation(string lakesPath, string swampsPath,
                        string badSoilsPath, string DEMpath, size_t length) {
    core = new Core(swampsPath, lakesPath, badSoilsPath);
    core->setDEM(DEMpath, length);
  }

  /* vector<Point> getBestSettlement(
       FilledPolygon protectionObject, float antennaHeight, float maxAngle,
       float minAngle, float shifAngle, const float flightAltitude,
       const float potentialRange, const float AWRange, size_t radarsNum,
       float ZRKRange, size_t frontWidth, float impactAngle) {
     FilledPolygon AWZone = protectionObject.getAviationWeapons(AWRange);
     vector<vector<Point>> DEM = core->getDEM();

     float distanse2Points = DEM[0][0].getX() - DEM[0][1].getX();
     float width = distanse2Points * DEM.size() - 1;
     float length = distanse2Points * DEM[0].size() - 1;

     FilledPolygon frontZone =
         getFrontZone(AWZone, frontWidth, impactAngle, length, width);

     FilledPolygon radarZone = getRadarZone(frontZone, ZRKRange);
     FilledPolygon targetCoverageZone = getTargetZone(frontZone, radarZone);

     MultiPoint targetCoverageZoneHeigth = getTZHeights(DEM,
   targetCoverageZone);

     size_t shift = frontWidth / (radarsNum / 3);
     shift /= distanse2Points;
     if (shift <= 0) shift = 1;

     triangles.clear();
     taggedPeaks.clear();

     Coordinates startInDEM = getCoordinateFromStr(
         targetCoverageZoneHeigth.getPoints()[0].getProperty("DEMXY"));

     genTriangles(targetCoverageZoneHeigth, shift, Coordinates(startInDEM));

     vector<vector<int>> combinations =
         generator.getPermutations(triangles.size(), radarsNum / 3);

     vector<Point> maxCoverage;
   }
 */

  vector<vector<Point>> getPermutationsPoints(vector<vector<int>> combinations,
                                              vector<Triangle> trianglesCopy) {
    vector<vector<Point>> result;
    vector<vector<Triangle>> trs;

    for (size_t i = 0; i < combinations.size(); i++) {
      vector<Triangle> tv;
      for (size_t j = 0; j < combinations[i].size(); j++) {
        tv.push_back(trianglesCopy[j]);
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
    Point *center = TZHeights.getFirstByPropetry(
        "DEMXY", size_t2Str(start.getX()) + " " + size_t2Str(start.getY()));

    Point *up = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX()) + " " + size_t2Str(start.getY() + shift));

    Point *down = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX()) + " " + size_t2Str(start.getY() - shift));

    Point *left = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX() - shift) + " " + size_t2Str(start.getY()));
    Point *right = TZHeights.getFirstByPropetry(
        "DEMXY",
        size_t2Str(start.getX() + shift) + " " + size_t2Str(start.getY()));

    taggedPeaks.push_back(*center);

    if (center && up && right && !core->isBadPoint(*up) &&
        !core->isBadPoint(*right)) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(up->getCoordinates());
      temp.addCoordinate(right->getCoordinates());

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && down && right && !core->isBadPoint(*right) &&
        !core->isBadPoint(*down)) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(down->getCoordinates());
      temp.addCoordinate(right->getCoordinates());

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && up && left && !core->isBadPoint(*up) &&
        !core->isBadPoint(*left)) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(up->getCoordinates());
      temp.addCoordinate(left->getCoordinates());

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && down && left && !core->isBadPoint(*down) &&
        !core->isBadPoint(*left)) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(down->getCoordinates());
      temp.addCoordinate(left->getCoordinates());

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

 private:
  bool isHasThisTriangle(Triangle t) {
    for (size_t i = 0; i < triangles.size(); i++) {
      if (triangles[i] == t) return true;
    }
    return false;
  }

  bool isPointInVector(vector<Point> v, Point _p) {
    for (size_t i = 0; i < v.size(); i++) {
      if (v[i] == _p) return true;
    }
    return false;
  }

  Core *core;
  vector<Triangle> triangles;
  vector<Point> taggedPeaks;
  PermutationsGenerator generator;
};

#endif  // SETTLEMENTCALCULATION_H
