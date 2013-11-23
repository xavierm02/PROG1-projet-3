#include "ray.hpp"

ray::ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color = rt::color::WHITE) :
  color(color), direction(direction), origin(origin) {
}

rt::vector ray::get_origin() {
  return origin;
}

rt::vector ray::get_direction() {
  return direction;
}

rt::color ray::get_color() {
  return color;
}
