#ifndef SSALGORITHMS_H
#define SSALGORITHMS_H

#include <cmath>
#include <vector>

#include "Coordinates.h"
#include "MultiFilledPolygon.h"
#include "Point.h"
#include "SSConstants.h"

using namespace std;

Point getP(int _heigh) {
  std::string height = std::to_string(_heigh);
  Point p;
  p.addProperty("height", height);
  p.addProperty("visible", "false");

  return p;
}

float getFloat(string str) { return ::atof(str.c_str()); }

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

bool isVectorHasProportion(vector<Coordinates> v, float proportion) {
  for (size_t i = 0; i < v.size(); i++) {
    if (v[i].getProportionXY() == proportion) return true;
  }
  return false;
}

vector<Coordinates> genShifts(size_t num) {
  num /= 4;
  vector<Coordinates> fourPath;
  fourPath.push_back(Coordinates(1, 1));

  Coordinates temp;
  size_t sz = 0;

  while (fourPath.size() <= num) {
    sz = fourPath.size();
    for (size_t i = 0; i < sz && fourPath.size() <= num; i++) {
      temp = fourPath[i];
      temp.setX(temp.getX() + 1);
      if (!isVectorHasProportion(fourPath, temp.getProportionXY()))
        fourPath.push_back(temp);
    }

    sz = fourPath.size();
    for (size_t i = 0; i < sz && fourPath.size() <= num; i++) {
      temp = fourPath[i];
      temp.setY(temp.getY() + 1);
      if (!isVectorHasProportion(fourPath, temp.getProportionXY()))
        fourPath.push_back(temp);
    }
  }

  vector<Coordinates> result;
  for (size_t i = 0; i < fourPath.size(); i++) {
    result.push_back(fourPath[i]);
    result.push_back(Coordinates(fourPath[i].getX(), -fourPath[i].getY()));
    result.push_back(Coordinates(-fourPath[i].getX(), fourPath[i].getY()));
    result.push_back(Coordinates(-fourPath[i].getX(), -fourPath[i].getY()));
  }

  result.push_back(Coordinates(0, -1));
  result.push_back(Coordinates(0, 1));
  result.push_back(Coordinates(1, 0));
  result.push_back(Coordinates(-1, 0));

  return result;
}

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

    if (curAngle >= minAngle && curAngle <= maxAngle)
      DEM[startY][startX].addProperty("visible", "true");

    float newMinAngl =
        findAgle(Coordinates(0, antennaZ), Coordinates(distance, pointHeight),
                 Coordinates(0, -10000.0));

    if (newMinAngl > minAngle) minAngle = newMinAngl;

    startX += shiftX;
    startY += shiftY;
    distance += xDistance;
  }
}

void findCoveragePoints(Point radarPos, float antennaHeight, float maxAngle,
                        float minAngle, float shifAngle,
                        vector<vector<Point>> &DEM, Coordinates startInMatrix,
                        const float flightAltitude, const float potentialRange,
                        float distance2Points) {
  size_t rayNum = CIRCLE_DEGREE / shifAngle;
  vector<Coordinates> shifts = genShifts(rayNum);

  for (size_t i = 0; i < shifts.size(); i++) {
    setVisibilityPoints(distance2Points, startInMatrix.getX(),
                        startInMatrix.getY(),
                        getFloat(radarPos.getProperty("height")), antennaHeight,
                        maxAngle, minAngle, shifts[i].getX(), shifts[i].getY(),
                        DEM, flightAltitude, potentialRange);
  }
}

FilledPolygon getFrontZone(FilledPolygon AWZone, size_t frontWidth,
                           float impactAngle, float lengthField,
                           float widthField) {
  Coordinates center = AWZone.getAvrXY();

  Coordinates leftLineStart(center.getX() - frontWidth / 2, center.getY());
  Coordinates rightLineStart(center.getX() + frontWidth / 2, center.getY());
  Coordinates secondPoint;

  FilledPolygon result;
  result.addCoordinate(rightLineStart);
  result.addCoordinate(leftLineStart);

  if (impactAngle >= 0 && impactAngle < 90) {
    secondPoint.setY(0);

    for (float i = leftLineStart.getX(); i <= lengthField; i += 0.1) {
      secondPoint.setX(i);

      if (fabs((findAgle(leftLineStart, center, secondPoint) - impactAngle)) <
          3) {
        result.addCoordinate(secondPoint);
        break;
      }
    }

    secondPoint.setX(lengthField - 1);
    for (float i = 0; i < widthField; i += 0.1) {
      secondPoint.setY(i);

      if (fabs(findAgle(leftLineStart, center, secondPoint) - impactAngle) <
          3) {
        result.addCoordinate(secondPoint);
        break;
      }
    }

    secondPoint.setY(0);
    for (float i = rightLineStart.getX(); i < lengthField; i += 0.1) {
      secondPoint.setX(i);

      if (fabs((180 - findAgle(rightLineStart, center, secondPoint) -
                impactAngle)) < 3) {
        result.addCoordinate(secondPoint);
        break;
      }
    }

    secondPoint.setX(lengthField - 1);
    for (float i = 0; i < widthField; i += 0.1) {
      secondPoint.setY(i);

      if (fabs(180 - findAgle(rightLineStart, center, secondPoint) -
               impactAngle) < 3) {
        result.addCoordinate(secondPoint);
        break;
      }
    }
  }
  /////////////
  /// ////////////
  /// ///////////
  /// //////////
  /////////

  if (impactAngle >= 90 && impactAngle < 180) {
    secondPoint.setY(0);

    for (float i = leftLineStart.getX(); i > 0; i -= 0.1) {
      secondPoint.setX(i);

      if (fabs(findAgle(leftLineStart, center, secondPoint) - impactAngle) <
          2) {
        result.addCoordinate(secondPoint);
        break;
      }
    }

    secondPoint.setX(0);
    secondPoint.setY(0);
    for (float i = 0; i < widthField; i += 0.1) {
      secondPoint.setY(i);

      if (fabs(findAgle(leftLineStart, center, secondPoint) - impactAngle) <
          2) {
        result.addCoordinate(secondPoint);
        break;
      }
    }

    secondPoint.setY(0);

    for (float i = rightLineStart.getX(); i > 0; i -= 0.1) {
      secondPoint.setX(i);

      if (fabs(180 - findAgle(rightLineStart, center, secondPoint) -
               impactAngle) < 2) {
        result.addCoordinate(secondPoint);
        break;
      }
    }

    secondPoint.setX(0);
    secondPoint.setY(0);
    for (float i = 0; i < widthField; i += 0.1) {
      secondPoint.setY(i);

      if (fabs(180 - findAgle(rightLineStart, center, secondPoint) -
               impactAngle) < 2) {
        result.addCoordinate(secondPoint);
        break;
      }
    }
  }

  return result;
}

Coordinates getSegment(Coordinates A, Coordinates B, float proportion) {
  Coordinates result;
  result.setX((A.getX() + proportion * B.getX()) / (1 + proportion));
  result.setY((A.getY() + proportion * B.getY()) / (1 + proportion));

  return result;
}

FilledPolygon getRadarZone(FilledPolygon frontZone, float length) {
  vector<Coordinates> points = frontZone.getPoints();
  float distance1 = findDistance(points[1], points[2]);
  float distance2 = findDistance(points[0], points[3]);

  float proportion1 = length / distance1;
  float proportion2 = length / distance2;

  proportion1 = proportion1 / (1 - proportion1);
  proportion2 = proportion2 / (1 - proportion2);

  Coordinates radarBorder1 = getSegment(points[1], points[2], proportion1);
  Coordinates radarBorder2 = getSegment(points[0], points[3], proportion2);

  FilledPolygon result;
  result.addCoordinate(points[0]);
  result.addCoordinate(points[1]);
  result.addCoordinate(radarBorder1);
  result.addCoordinate(radarBorder2);

  return result;
}

FilledPolygon getTargetZone(FilledPolygon frontZone, FilledPolygon radarZone) {
  vector<Coordinates> frontPoints = frontZone.getPoints();
  vector<Coordinates> radarPoints = radarZone.getPoints();

  FilledPolygon result;

  result.addCoordinate(radarPoints[3]);
  result.addCoordinate(radarPoints[2]);
  result.addCoordinate(frontPoints[2]);
  result.addCoordinate(frontPoints[3]);

  return result;
}

#endif  // SSALGORITHMS_H
