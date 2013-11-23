#include <cmath>

#include "plane.hpp"

plane::plane(rt::vector& origin, rt::vector& normal_vector) :
  normal_vector(normal_vector), origin(origin) {
}

rt::vector plane::get_normal_vector() const {
  return normal_vector;
}

rt::vector plane::get_origin() const {
  return origin;
}

option<rt::vector> plane::get_point_of_incidence_of(ray ray) {
    if ((ray.get_direction() ^ normal_vector).norm() <= 0.001) {// TODO global epsilon?
      // ray parallel to the plane
      return option<rt::vector>(false, rt::vector());
    } else {
      double a = (origin - ray.get_origin()) | normal_vector;
      double b = ray.get_direction() | normal_vector;
      if (std::signbit(a) != std::signbit(b)) {
        // ray going away from the plane
        return option<rt::vector>(false, rt::vector());
      } else {
        return option<rt::vector>(true, ray.get_origin() + (a/b) * ray.get_direction());
      }
    }
}
