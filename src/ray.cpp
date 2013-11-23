#include "ray.hpp"

ray::ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color = rt::color::WHITE) :
  color(color), direction(direction), origin(origin) {
}

rt::color ray::get_color() const {
  return color;
}

rt::vector ray::get_direction() const {
  return direction;
}

rt::vector ray::get_origin() const {
  return origin;
}
