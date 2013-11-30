#include "Ray.hpp"

Ray::Ray(const Point& origin, const UnitVector& direction, const unsigned int propagations_left) :
  direction(direction),
  origin(origin),
  propagations_left(propagations_left) {
}

UnitVector Ray::get_direction() const {
  return direction;
}

Point Ray::get_origin() const {
  return origin;
}

unsigned int Ray::get_propagations_left() const {
  return propagations_left;
}
