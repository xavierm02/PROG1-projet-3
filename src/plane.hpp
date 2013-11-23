#ifndef __PLANE_H
#define __PLANE_H

#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include "option.hpp"

class plane : public object {
private:
  rt::vector normal_vector;
  rt::vector origin;
public:
  plane(rt::vector& origin, rt::vector& normal_vector);

  rt::vector get_normal_vector() const;
  rt::vector get_origin() const;

  option<rt::vector> get_point_of_incidence_of(ray ray);
  /*
  rt::vector intersection(ray r);
  double dist(ray r);*/
};

#endif
