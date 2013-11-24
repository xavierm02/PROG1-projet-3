#include "Ray.hpp"

Ray::Ray(const Point& origin, const rt::vector& direction) :
  direction(direction.unit()), origin(origin) {
}

rt::vector Ray::get_direction() const {
  return direction;
}

Point Ray::get_origin() const {
  return origin;
}
