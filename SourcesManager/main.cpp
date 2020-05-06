#include <cstring>
#include <iostream>
#include <string>

#include "entities/Algorithms.h"
#include "entities/Triangle.h"

using namespace std;
using namespace figureTypes;

int main() {
  Coordinates s(2, 3);
  Coordinates e(3, 1);
  Coordinates s1(7, 3);
  Coordinates e1(6, 1);
  Coordinates p(1, 2);
  Coordinates rez(2.5, 2);
  Coordinates rez1(6.5, 2);

  intersPointLineByOX(p, s, e);
  intersPointLineByOX(p, e, s);
  intersPointLineByOX(p, s1, e1);
  intersPointLineByOX(p, e1, s1);
}
