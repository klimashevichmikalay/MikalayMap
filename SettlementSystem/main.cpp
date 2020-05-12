#include <iostream>

#include "ParsersCommand.h"
#include "SSAlgorithms.h"

using namespace std;

Point getP(int _heigh) {
  std::string height = std::to_string(_heigh);
  Point p;
  p.addProperty("height", height);
  p.addProperty("visible", "false");

  return p;
}

int main() {
  size_t maxY = 8;
  vector<vector<Point>> DEM;
  vector<Point> v0;
  vector<Point> v1;
  vector<Point> v2;
  vector<Point> v3;
  vector<Point> v4;
  vector<Point> v5;
  vector<Point> v6;
  vector<Point> v7;
  vector<Point> v8;
  vector<Point> v9;

  for (size_t i = 0; i < maxY; i++) {
    v3.push_back(getP(750));

    if (i == 0) {
      v7.push_back(getP(100));
      v8.push_back(getP(100));
      v9.push_back(getP(100));
    }

    if (i == 1 || i == 2) {
      v7.push_back(getP(-45));
      v8.push_back(getP(-45));
      v9.push_back(getP(-45));
    }

    if (i < 3) {
      v0.push_back(getP(50));
      v1.push_back(getP(50));
      v2.push_back(getP(50));
      v4.push_back(getP(50));
      v5.push_back(getP(50));
      v6.push_back(getP(50));
    }

    if (i == 3) {
      v0.push_back(getP(750));
      v1.push_back(getP(750));
      v2.push_back(getP(750));

      v4.push_back(getP(50));
      v5.push_back(getP(50));
      v6.push_back(getP(50));

      v7.push_back(getP(50));
      v8.push_back(getP(50));
      v9.push_back(getP(50));
    }

    if (i > 3) {
      v0.push_back(getP(50));
      v1.push_back(getP(50));
      v2.push_back(getP(50));
      v4.push_back(getP(50));
    }

    if (i == 4) {
      v6.push_back(getP(50));
      v7.push_back(getP(750));
      v8.push_back(getP(50));
      v9.push_back(getP(50));
    }

    if (i > 4) {
      v7.push_back(getP(50));
      v8.push_back(getP(50));
      v9.push_back(getP(50));
    }

    if (i == 5) {
      v6.push_back(getP(750));
    }

    if (i == 4 || i == 5) {
      v5.push_back(getP(50));
    }

    if (i == 6 || i == 7) {
      v5.push_back(getP(100));
      v6.push_back(getP(100));
    }
  }

  DEM.push_back(v0);
  DEM.push_back(v1);
  DEM.push_back(v2);
  DEM.push_back(v3);
  DEM.push_back(v4);
  DEM.push_back(v5);
  DEM.push_back(v6);
  DEM.push_back(v7);
  DEM.push_back(v8);
  DEM.push_back(v9);

  setVisibilityPoints(100, 3, 7, 90, 10, 120, 80, 1, 1, DEM, 50, 10000);

  for (size_t i = 0; i < DEM.size(); i++) {
    for (size_t j = 0; j < DEM[i].size(); j++) {
      string prop = DEM[i][j].getProperty("height");

      if (prop.length() < 2) {
        cout << "     " << prop;
      } else

          if (prop.length() < 3) {
        cout << "    " << prop;
      } else
        cout << "   " << prop;
    }
    cout << endl << endl;
  }

  return 0;
}
