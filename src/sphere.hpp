#ifndef __SPHERE_H
#define __SPHERE_H


#include "vector.hpp"
#include "ray.hpp"

class sphere {
private:
  rt::vector _center;
  double _radius;
  rt::color _color;
public:
  rt::vector get_center();
  void set_center(rt::vector c);
  double get_radius();
  void set_radius(double r);
  bool does_intersect(ray r);
  rt::vector intersection(ray r);
  rt::vector normal_vector(ray r);
};

#endif
