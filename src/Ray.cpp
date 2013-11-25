#include "Ray.hpp"

Ray::Ray(const Point& origin, const rt::vector& direction, const unsigned int propagations_left) :
  direction(direction.unit()), origin(origin), propagations_left(propagations_left) {
}

rt::vector Ray::get_direction() const {
  return direction;
}

Point Ray::get_origin() const {
  return origin;
}
