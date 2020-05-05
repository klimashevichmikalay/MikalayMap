#ifndef POINT_H
#define POINT_H

#include "BaseFigure.h"
#include "Coordinates.h"
#include "FiguresTypes.h"
#include "Scale.h"

class Point : public BaseFigure, public Scale {
 public:
  float getX();
  float getY();
  void setX(float _X);
  void setY(float _Y);
  void setCoordinates(Coordinates _location);
  Coordinates getCoordinates();
  void minusDelta(Coordinates _delta);

  Point();
  Point(const std::string &_name);
  Point(const char *_name);
  Point(Coordinates _location);
  Point(const std::string &_name, Coordinates _location);
  Point(const char *_name, Coordinates _location);

  Coordinates getAvrXY() { return location; };
  void scalingByArea(float _area, bool _isShift) {
    float factor = sqrt(_area);
    scalingByFactor(factor, _isShift);
  };
  void scalingByFactor(float _scale, bool _isShift) {
    float oldX = location.getX();
    float oldY = location.getY();

    location.setX(oldX * _scale);
    location.setY(oldY * _scale);

    scale *= _scale;

    if (_isShift) {
      location.setX(oldX);
      location.setY(oldY);
    }
  }

  bool operator==(Point obj);

 private:
  Coordinates location;
};

#endif  // POINT_H
