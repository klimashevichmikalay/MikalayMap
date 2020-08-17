#include "Coordinates.h"

#include <math.h>

using namespace Geometry;
const double Coordinates::epsilon = 0.0001;

double Coordinates::getX() const {
  return X;
}

double Coordinates::getY() const {
  return Y;
}

double& Coordinates::refX() {
  return X;
}

double& Coordinates::refY() {
  return Y;
}

void Coordinates::setX(double x) {
  X = x;
}

void Coordinates::setY(double y) {
  Y = y;
}

double Coordinates::getProportionXY() const {
  return X / Y;
}

void Coordinates::shift(const Coordinates& delta) {
  *this += delta;
}

void Coordinates::scalingByFactor(const double& factor, bool isShift) {
  scale *= factor;

  if (isShift)
    return;
  else
    *this *= factor;
}

void Coordinates::mult(double factor) {
  *this *= factor;
}

Coordinates Coordinates::countSum() const {
  return *this;
}

unsigned Coordinates::countObjs() const {
  return 1;
}

Coordinates::Coordinates() : X(0.0), Y(0.0){};

Coordinates::Coordinates(double x, double y) {
  X = x;
  Y = y;
}

Coordinates::~Coordinates() {}

bool Coordinates::operator==(const Coordinates& obj) const {
  return IScale::operator==(obj) &&
         (fabs(X - obj.X) <= epsilon && fabs(Y - obj.Y) <= epsilon);
}

Coordinates& Coordinates::operator+=(const Coordinates& obj) {
  X += obj.X;
  Y += obj.Y;
  return *this;
}

Coordinates& Coordinates::operator-=(const Coordinates& obj) {
  X -= obj.X;
  Y -= obj.Y;
  return *this;
}

Coordinates& Coordinates::operator/=(double f) {
  X /= f;
  Y /= f;
  return *this;
}

Coordinates& Coordinates::operator*=(double f) {
  X *= f;
  Y *= f;
  return *this;
}

Coordinates& Coordinates::operator=(const Coordinates& obj) {
  X = obj.X;
  Y = obj.Y;
  return *this;
}
