#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include <iostream>

rt::color object::get_color() {
  return _color;
}
void object::set_color(rt::color color) {
  _color = color;
}
