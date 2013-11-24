#include <cmath>

#include "Plane.hpp"

Plane::Plane(const Point& origin, rt::vector& normal_vector) :
  normal_vector(normal_vector.unit()), origin(origin) {
}

Plane* Plane::clone() const {
  return new Plane(*this);
}

rt::vector Plane::get_normal_vector() const {
  return normal_vector;
}

Point Plane::get_origin() const {
  return origin;
}

bool Plane::intersects(const Ray& ray, double *distance) {
    if ((ray.get_direction() ^ normal_vector).norm() <= 0.001) {// TODO global epsilon?
      // The ray is parallel to the plane
      return false;
    }
    double a = (origin - ray.get_origin()) | normal_vector;
    double b = ray.get_direction() | normal_vector;
    if (std::signbit(a) != std::signbit(b)) {
      // The ray isn't heading towards the plane
      return false;
    }
    *distance = a / b;
    return true;
}

