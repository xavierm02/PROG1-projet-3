#include <iostream>
#include "vector.hpp"
#include "color.hpp"
#include "Source.hpp"



Source::Source(const Point& origin, const Light& light) :
  light(light), origin(origin) {
}

Light Source::get_light() const {
  return light;
}

Point Source::get_origin() const {
  return origin;
}

Ray Source::send_ray_towards(const Point& point) const {
  return Ray(origin, point-origin, 0);
}
