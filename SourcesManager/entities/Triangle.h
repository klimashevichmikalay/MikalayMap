#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "ExceptionsMsgs.h"
#include "GeometryConstants.h"  //TRIANGLE_SZ
#include "MultiFigure.h"
#include "Point.h"

namespace Geometry {

class Triangle : public BaseFigure, public MultiFigure<Point*, Point> {
 public:
  void addObject(const Point& p) override;
  unsigned getSZ() const;

  void clear();

  Triangle();
  Triangle(const std::string& name);
  ~Triangle();

  Triangle& operator=(const Triangle& obj);
  bool operator==(const Triangle& obj);

 protected:
  unsigned objectsSZ{0};
};
}  // namespace Geometry

#endif  // TRIANGLE_H
