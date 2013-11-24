#ifndef __SPHERE_H
#define __SPHERE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"

class Sphere : public Object {
private:
  rt::vector center;
  double radius;

public:
  Sphere(const rt::vector& center, double radius);
  Sphere* clone() const;

  rt::vector get_center();
  double get_radius();

  bool intersects(Ray ray, double *distance);
};

#endif
