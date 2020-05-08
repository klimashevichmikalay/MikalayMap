#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "entities/MultiFilledPolygon.h"
#include "entities/MultiLineString.h"
#include "entities/MultiPoint.h"
#include "parsers/BaseFigureParser.h"
#include "parsers/CoordinatesParser.h"
#include "parsers/FilledPolygonParser.h"
#include "parsers/LineStringParser.h"
#include "parsers/MultiFilledPolygonParser.h"
#include "parsers/MultiLineParser.h"
#include "parsers/ParsersConstants.h"

using namespace std;
using namespace figureTypes;

string readFile(string _path) {
  std::ifstream t(COORDINATES_PATH + _path);
  if (!t) cout << "Can not open file";

  std::string str((std::istreambuf_iterator<char>(t)),
                  std::istreambuf_iterator<char>());

  return str;
}

int main() {
  MultiFilledPolygon mlBefore("name");

  FilledPolygon line1("linename");
  FilledPolygon line2;
  FilledPolygon line3;

  line1.addCoordinate(Coordinates(3, 1));
  line1.addCoordinate(Coordinates(2, 3));
  line1.addCoordinate(Coordinates(4, 4));
  line2.addCoordinate(Coordinates(6, 2));
  line2.addCoordinate(Coordinates(6, 0));
  line2.addCoordinate(Coordinates(4, 3));
  line3.addCoordinate(Coordinates(3, 2));

  mlBefore.addPolygon(line1);
  mlBefore.addPolygon(line2);
  mlBefore.addPolygon(line3);

  StringBuffer sb;
  PrettyWriter<StringBuffer> writer(sb);
  mfpToJSON(mlBefore, writer);

  puts(sb.GetString());

  return 0;
}
