#ifndef MULTIFILLEDPOLYGON_H
#define MULTIFILLEDPOLYGON_H

#include "BaseFigure.h"
#include "FilledPolygon.h"
#include "Scale.h"

class MultiFilledPolygon : public BaseFigure, public Scale {
 public:
  std::vector<FilledPolygon> getPolygons();
  bool isContains(FilledPolygon _polygon);
  void addPolygon(FilledPolygon _polygon);
  void clear();

  MultiFilledPolygon();
  MultiFilledPolygon(const char *_name);
  MultiFilledPolygon(const std::string &_name);
  bool operator==(MultiFilledPolygon obj);

  Coordinates getAvrXY();
  void multCoordinates(float _factor);
  void minusCoordinates(Coordinates _delta);
  void scalingByArea(float _area, bool _isShift);
  void scalingByFactor(float _scale, bool _isShift);

  FilledPolygon *getFirstByPropetry(std::string propName, std::string propVal) {
    FilledPolygon *result = new FilledPolygon;

    for (size_t i = 0; i < polygons.size(); i++) {
      std::string prop = polygons[i].getProperty(propName);
      if (prop.compare(propVal) == 0) {
        *result = polygons[i];
        return result;
      }
    }
    return nullptr;
  }

 protected:
  std::vector<FilledPolygon> polygons;
};

#endif  // MULTIFILLEDPOLYGON_H
