#ifndef MULTIPOINT_H
#define MULTIPOINT_H
#include <vector>

#include "FiguresTypes.h"
#include "Point.h"

class MultiPoint : public BaseFigure {
 public:
  std::vector<Point> getPoints();
  bool isContains(Point _point);
  void addPoint(Point _point);
  void clear();

  MultiPoint();
  MultiPoint(const char *_name);
  MultiPoint(const std::string &_name);
  MultiPoint(const char *_name, const figureTypes::FigureType &_type);
  MultiPoint(const std::string &_name, const figureTypes::FigureType &_type);

  bool operator==(MultiPoint obj);

 private:
  std::vector<Point> points;
};

#endif  // MULTIPOINT_H
