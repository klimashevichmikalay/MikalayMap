#include <assert.h>

#include <iostream>

#include "ParsersCommand.h"
#include "PermutationsGenerator.h"
#include "SSAlgorithms.h"
#include "SettlementCalculation.h"

using namespace std;

Point getP(int _heigh, int x, int y) {
  std::string height = std::to_string(_heigh);
  Point p(Coordinates(x, y));
  p.addProperty("height", height);
  p.addProperty("visible", "false");

  return p;
}

int main() {
  vector<FilledPolygon> lakes;

  vector<Point> dem;

  for (int i = 0; i <= 255; i++) {
    if (i >= 77 && i <= 84) {
      dem.push_back(getP(15000, (i % 16) * 2, i / 16 * 2));
      continue;
    }

    dem.push_back(getP(100, (i % 16) * 2, i / 16 * 2));
  }

  FilledPolygon lake;
  lake.addCoordinate(Coordinates(13, 20));
  lake.addCoordinate(Coordinates(7, 20));
  lake.addCoordinate(Coordinates(7, 12));
  lake.addCoordinate(Coordinates(13, 12));

  lakes.push_back(lake);

  ParsersCommand pc;
  pc.getParser(JSON)->savePoints(dem, "demTest");
  pc.getParser(JSON)->saveFilledPolygons(lakes, "lakesTest");
  pc.getParser(JSON)->saveFilledPolygons(lakes, "swTest");
  pc.getParser(JSON)->saveFilledPolygons(lakes, "badTest");

  SettlementCalculation sc("lakesTest", "swTest", "badTest", "demTest", 16);

  FilledPolygon f;
  f.addCoordinate(Coordinates(18, 22));
  f.addCoordinate(Coordinates(19, 20));
  f.addCoordinate(Coordinates(20, 21));

  vector<Point> settlement =
      sc.getBestSettlement(f, 0, 120, 70, 2.5, 0, 20, 2, 3, 11, 22, 135);

  vector<vector<Point>> DEM = sc.getCore()->getDEM();

  return 0;
}

/* FilledPolygon pBefore;

 pBefore.addCoordinate(Coordinates(3, 1));
 pBefore.addCoordinate(Coordinates(2, 3));
 pBefore.addCoordinate(Coordinates(4, 4));
 pBefore.addCoordinate(Coordinates(6, 2));
 pBefore.addCoordinate(Coordinates(6, 0));
 //  pBefore.addCoordinate(Coordinates(4, 3));
 //  pBefore.addCoordinate(Coordinates(3, 2));

 FilledPolygon fp = pBefore.getAviationWeapons(2);

 cout << endl;
}*/
/*

Point getP(int _heigh) {
  std::string height = std::to_str``ing(_heigh);
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

  for (size_t i = 0; i < DEM.size(); i++) {
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
  }

  Point radarPos;
  radarPos.addProperty("height", "80");
  findCoveragePoints(radarPos, 20, 120, 80, 2.5, DEM, Coordinates(35, 1), 50,
                     10000, 50);

  for (size_t i = 0; i < DEM.size(); i++) {
    for (size_t j = 0; j < DEM[i].size(); j++) {
      string prop = DEM[i][j].getProperty("visible");

      cout << ((prop.compare("true") == 0) ? "#" : "_") << "  ";
    }
    cout << endl;
  }

  void findCoveragePoints(Point radarPos, float antennaHeight, float maxAngle,
                      float minAngle, float shifAngle,
                      vector<vector<Point>> &DEM, Coordinates startInMatrix,
                      const float flightAltitude, const float potentialRange,
                      float distance2Points)

  return 0;
}
*/
