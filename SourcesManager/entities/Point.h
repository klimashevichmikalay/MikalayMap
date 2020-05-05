#ifndef POINT_H
#define POINT_H

#include "BaseFigure.h"
#include "Coordinates.h"
#include "FiguresTypes.h"

class Point : public BaseFigure {
 public:
  float getX();
  float getY();
  void setX(float _X);
  void setY(float _Y);
  void setCoordinates(Coordinates _location);
  Coordinates getCoordinates();

  Point();
  Point(const std::string &_name);
  Point(const char *_name);
  Point(Coordinates _location);
  Point(const std::string &_name, Coordinates _location);
  Point(const char *_name, Coordinates _location);

  bool operator==(Point obj);

 private:
  Coordinates location;
};

#endif  // POINT_H
