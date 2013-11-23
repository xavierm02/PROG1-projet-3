#include "object.hpp"
#include "vector.hpp"
#include "color.hpp"
#include "ray.hpp"

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

bool plane::does_intersect(ray ray) {
    if ((ray.get_direction() ^ normal_vector).norm() <= 0.001) {// TODO global epsilon?
      // ray parallel to the plane
      return false;
    } else {
      double a = (origin - ray.get_origin()) | normal_vector;
      double b = ray.get_direction() | normal_vector;
      if (a * b < 0) {
        // ray going away from the plane
        return false;
      } else {
        return true;
      }
    }
}
/*
rt::vector plan::intersection(ray r) {

    double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction()|_normal_vector);
  return (r.get_origin()+(t*r.get_direction()));
}

double plan::dist(ray r) {
    double t = ( (_origin|_normal_vector)-(r.get_origin()|_normal_vector) )/(r.get_direction().unit()|_normal_vector);
  return t;
}

*/





