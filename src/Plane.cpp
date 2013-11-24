#include <cmath>

#include "Plane.hpp"

Plane::Plane(rt::vector& origin, rt::vector& normal_vector) :
  normal_vector(normal_vector), origin(origin) {
}

rt::vector Plane::get_normal_vector() const {
  return normal_vector;
}

rt::vector Plane::get_origin() const {
  return origin;
}

Option<rt::vector> Plane::get_point_of_incidence_of(Ray ray) {
    if ((ray.get_direction() ^ normal_vector).norm() <= 0.001) {// TODO global epsilon?
      // ray parallel to the plane
      return Option<rt::vector>();
    } else {
      double a = (origin - ray.get_origin()) | normal_vector;
      double b = ray.get_direction() | normal_vector;
      if (std::signbit(a) != std::signbit(b)) {
        // ray going away from the plane
        return Option<rt::vector>();
      } else {
        return Option<rt::vector>(ray.get_origin() + (a/b) * ray.get_direction());
      }
    }
}

