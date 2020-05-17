#ifndef SETTLEMENTCALCULATION_H
#define SETTLEMENTCALCULATION_H

#include "Core.h"
#include "SSAlgorithms.h"
#include "SSConstants.h"

class SettlementCalculation {
 public:
  SettlementCalculation() { core = new Core(); }
  SettlementCalculation(string lakesPath, string swampsPath,
                        string badSoilsPath, string DEMpath, size_t length) {
    core = new Core(swampsPath, lakesPath, badSoilsPath);
    core->setDEM(DEMpath, length);
  }

  /*vector<Point> getBestSettlement(FilledPolygon protectionObject,
    float antennaHeight, float maxAngle,
    float minAngle, float shifAngle,
    const float flightAltitude,
    const float potentialRange,
    const float AWRange) {




     triangles.clear();
taggedPeaks.clear();

}*/
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

    if (center && up && right) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(up->getCoordinates());
      temp.addCoordinate(right->getCoordinates());

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && down && right) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(down->getCoordinates());
      temp.addCoordinate(right->getCoordinates());

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && up && left) {
      Triangle temp;
      temp.addCoordinate(center->getCoordinates());
      temp.addCoordinate(up->getCoordinates());
      temp.addCoordinate(left->getCoordinates());

      if (!isHasThisTriangle(temp)) {
        triangles.push_back(temp);
      }
    }

    if (center && down && left) {
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
};

#endif  // SETTLEMENTCALCULATION_H
