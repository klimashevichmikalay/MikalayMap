#include <cstring>
#include <iostream>
#include <string>

#include "entities/Coordinates.h"
#include "entities/LineString.h"
#include "entities/Point.h"

using namespace std;
using namespace figureTypes;

float rounded(float _num) { return floorf(_num * 100) / 100; }

int main() {
  cout << "tgtgtgttg";

  LineString lsBefore;
  LineString lsAfter;

  lsBefore.addCoordinate(Coordinates(3, 1));
  lsBefore.addCoordinate(Coordinates(2, 3));
  lsBefore.addCoordinate(Coordinates(4, 4));
  lsBefore.addCoordinate(Coordinates(6, 2));
  lsBefore.addCoordinate(Coordinates(6, 0));
  lsBefore.addCoordinate(Coordinates(4, 3));
  lsBefore.addCoordinate(Coordinates(3, 2));

  lsAfter.addCoordinate(Coordinates(2.59, 0.53));
  lsAfter.addCoordinate(Coordinates(1.18, 3.35));
  lsAfter.addCoordinate(Coordinates(4, 4.76));
  lsAfter.addCoordinate(Coordinates(6.82, 1.94));
  lsAfter.addCoordinate(Coordinates(6.82, -0.87));
  lsAfter.addCoordinate(Coordinates(4, 3.35));
  lsAfter.addCoordinate(Coordinates(2.59, 1.94));

  lsBefore.scalingByArea(2);
}
