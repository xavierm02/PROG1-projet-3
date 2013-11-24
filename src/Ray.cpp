#include "Ray.hpp"

Ray::Ray(const Point& origin, const rt::vector& direction, const rt::color& color = rt::color::WHITE) :
  color(color), direction(direction), origin(origin) {
}

rt::color Ray::get_color() const {
  return color;
}

rt::vector Ray::get_direction() const {
  return direction;
}

Point Ray::get_origin() const {
  return origin;
}
