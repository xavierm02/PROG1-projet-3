#include <iostream>
#include "vector.hpp"
#include "color.hpp"
#include "source.hpp"



source::source(const rt::vector& origin, const rt::color& color = rt::color::WHITE) :
  color(color), origin(origin) {
}

rt::color source::get_color() const {
  return color;
}

rt::vector source::get_origin() const {
  return origin;
}
