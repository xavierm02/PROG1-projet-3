#include "ray.hpp"

ray::ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color, double intensity) {
  _origin = origin;
  _direction = direction;
  _color = color;
  _intensity = intensity;
}
