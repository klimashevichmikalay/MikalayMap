#ifndef COORDINATES_H
#define COORDINATES_H

#include <math.h>

class Coordinates {
 public:
  Coordinates();
  Coordinates(float _x, float _y);
  bool operator==(const Coordinates &obj);

  float getX();
  float getY();
  void setX(float _x);
  void setY(float _y);

 private:
  float round(float _num);
  float X;
  float Y;
};

#endif  // COORDINATES_H
