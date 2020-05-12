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

  float getProportionXY() { return X / Y; }

  void operator+=(const Coordinates &obj) {
    X += obj.X;
    Y += obj.Y;
  }

  void operator-=(const Coordinates &obj) {
    X -= obj.X;
    Y -= obj.Y;
  }

  void operator/=(float _f) {
    X /= _f;
    Y /= _f;
  }

  void operator*=(float _f) {
    X *= _f;
    Y *= _f;
  }

 private:
  float round(float _num);
  float X;
  float Y;
};

#endif  // COORDINATES_H
