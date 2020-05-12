#ifndef SSALGORITHMS_H
#define SSALGORITHMS_H

#include <cmath>
#include <vector>

#include "Coordinates.h"
#include "Point.h"
#include "SSConstants.h"

using namespace std;

float findDistance(Coordinates p1, Coordinates p2) {
  return sqrt(pow((p1.getX() - p2.getX()), 2.0) +
              pow((p1.getY() - p2.getY()), 2.0));
}

float findAgle(Coordinates p1, Coordinates p2, Coordinates p3) {
  float P12 = findDistance(p1, p2);
  float P13 = findDistance(p1, p3);
  float P23 = findDistance(p2, p3);

  return acos((P12 * P12 + P13 * P13 - P23 * P23) / (2 * P12 * P13)) *
         HALF_CIRCLE_DEGREE / PI;
};

void setVisibilityPoints(float distance2Points, size_t startX, size_t startY,
                         const float radarHeight, const float antennaHeight,
                         const float maxAngle, float minAngle, const int shiftX,
                         const int shiftY, vector<vector<Point>> &DEM,
                         const float flightAltitude,
                         const float potentialRange) {
  const float antennaZ = radarHeight + antennaHeight;
  float xDistance =
      sqrt(pow(shiftX * distance2Points, 2) + pow(shiftY * distance2Points, 2));
  float distance = 0;
  float curAngle = 0;

  startX += shiftX;
  startY += shiftY;
  distance += xDistance;

  while (startX < DEM.at(0).size() && startX >= 0 && startY < DEM.size() &&
         startY >= 0) {
    if (minAngle >= maxAngle || distance >= potentialRange) return;

    float pointHeight =
        ::atof(DEM[startY][startX].getProperty("height").c_str());

    curAngle = findAgle(Coordinates(0, antennaZ),
                        Coordinates(distance, flightAltitude + pointHeight),
                        Coordinates(0, -10000.0));

    Point curP = DEM[startY][startX];
    if (curAngle >= minAngle && curAngle <= maxAngle) {
      curP.addProperty("visible", "true");
    }

    DEM[startY][startX] = curP;

    float newMinAngl =
        findAgle(Coordinates(0, antennaZ), Coordinates(distance, pointHeight),
                 Coordinates(0, -10000.0));

    if (newMinAngl > minAngle) minAngle = newMinAngl;

    startX += shiftX;
    startY += shiftY;
    distance += xDistance;
  }
}

#endif  // SSALGORITHMS_H
