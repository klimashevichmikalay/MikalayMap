#include "Coordinates.h"

#include <math.h>

using namespace Geometry;
const double Coordinates::epsilon = 0.0001;

Coordinates::Coordinates() : X(0.0), Y(0.0){};

Coordinates::Coordinates(double x, double y) {
  X = x;
  Y = y;
}

bool Coordinates::operator==(const Coordinates& obj) const {
  return (fabs(X - obj.X) <= epsilon && fabs(Y - obj.Y) <= epsilon);
}

double Coordinates::getX() const {
  return X;
}

double Coordinates::getY() const {
  return Y;
};

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
