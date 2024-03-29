#include "ray.hpp"

ray::ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color, double intensity) {
  _origin = origin;
  _direction = direction;
  _color = color;
  _intensity = intensity;
}

ray::ray(const rt::vector& origin, const rt::vector& direction) {
  _origin = origin;
  _direction = direction;
  _color = rt::color::WHITE;
  _intensity = 1.0;
}

rt::vector ray::get_origin() {
  return _origin;
}

rt::vector ray::get_direction() {
  return _direction;
}
