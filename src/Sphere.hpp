#ifndef __SPHERE_H
#define __SPHERE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"

class Sphere : public Object {
private:
  Point center;
  double radius;

public:
  Sphere(const Point& center, double radius);
  Sphere* clone() const;

  Point get_center();
  double get_radius();

  bool intersects(const Ray& ray, double *distance);
};

#endif
