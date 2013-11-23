#ifndef __PLANE_H
#define __PLANE_H

#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"

class plane : public object {
private:
  rt::vector normal_vector;
  rt::vector origin;
public:
  plane(rt::vector& origin, rt::vector& normal_vector);

  rt::vector get_normal_vector() const;
  rt::vector get_origin() const;

  bool does_intersect(ray ray);
  /*
  rt::vector intersection(ray r);
  double dist(ray r);*/
};

#endif
