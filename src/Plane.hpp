#ifndef __PLANE_H
#define __PLANE_H

#include "vector.hpp"
#include "Ray.hpp"
#include "Object.hpp"
#include "Option.hpp"

class Plane : public Object {
private:
  rt::vector normal_vector;
  rt::vector origin;
public:
  Plane(rt::vector& origin, rt::vector& normal_vector);

  rt::vector get_normal_vector() const;
  rt::vector get_origin() const;

  rt::vector get_point_of_incidence_of(Ray ray);
  /*
  rt::vector intersection(ray r);
  double dist(ray r);*/
};

#endif
