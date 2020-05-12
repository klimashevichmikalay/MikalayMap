#include <assert.h>

#include <iostream>

#include "ParsersCommand.h"
#include "SSAlgorithms.h"

using namespace std;
/*
int main() {
  vector<Coordinates> v = genShifts(36);

  for (size_t i = 0; i < v.size(); i++) {
    for (size_t j = i + 1; j < v.size(); j++) {
      assert(fabs(v[i].getProportionXY() - v[j].getProportionXY()));
    }
  }

  cout << endl;
}
*/

Point getP(int _heigh) {
  std::string height = std::to_string(_heigh);
  Point p;
  p.addProperty("height", height);
  p.addProperty("visible", "false");

  return p;
}

int main() {
  vector<vector<Point>> DEM;

  for (int i = 0; i < 40; i++) {
    vector<Point> v;
    DEM.push_back(v);
  }

  for (int i = 0; i < 40; i++) {
    if (i < 11) {  //+
      for (int j = 30; j < 40; j++) DEM[j].push_back(getP(50));
    }

    if (i > 10 && i < 20) {  //+
      for (int j = 30; j < 40; j++) DEM[j].push_back(getP(5000));
    }

    if (i < 23) {  //+
      for (int j = 0; j < 11; j++) DEM[j].push_back(getP(50));

      for (int j = 11; j < 19; j++) DEM[j].push_back(getP(5000));

      for (int j = 19; j < 30; j++) DEM[j].push_back(getP(50));
    }

    if (i >= 20 && i < 40) {  //+
      for (int j = 30; j < 40; j++) DEM[j].push_back(getP(-100));
    }

    if (i > 22) {  //+
      for (int j = 19; j < 30; j++) DEM[j].push_back(getP(50));
    }

    if (i > 29) {  //+
      for (int j = 12; j < 19; j++) DEM[j].push_back(getP(5000));
    }

    if (i > 22 && i < 30) {
      for (int j = 12; j < 19; j++) DEM[j].push_back(getP(50));
    }

    if (i > 22) {
      for (int j = 0; j < 12; j++) DEM[j].push_back(getP(50));
    }
  }

  /*for (size_t i = 0; i < DEM.size(); i++) {
    for (size_t j = 0; j < DEM[i].size(); j++) {
      string prop = DEM[i][j].getProperty("height");

      if (prop.length() == 2) {
        cout << "   " << prop;
      } else

          if (prop.length() == 4) {
        cout << " " << prop;
      } else
        cout << "  " << prop;
    }
    cout << endl;
  }*/

  Point radarPos;
  radarPos.addProperty("height", "80");
  findCoveragePoints(radarPos, 20, 120, 80, 2.5, DEM, Coordinates(20, 29), 50,
                     1000, 100);

  for (size_t i = 0; i < DEM.size(); i++) {
    for (size_t j = 0; j < DEM[i].size(); j++) {
      string prop = DEM[i][j].getProperty("visible");

      cout << ((prop.compare("true") == 0) ? "#" : "_") << "  ";
    }
    cout << endl;
  }

  /*void findCoveragePoints(Point radarPos, float antennaHeight, float maxAngle,
                      float minAngle, float shifAngle,
                      vector<vector<Point>> &DEM, Coordinates startInMatrix,
                      const float flightAltitude, const float potentialRange,
                      float distance2Points)*/

  return 0;
}
