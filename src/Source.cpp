#include <iostream>
#include "vector.hpp"
#include "color.hpp"
#include "Source.hpp"



Source::Source(const rt::vector& origin, const rt::color& color = rt::color::WHITE) :
  color(color), origin(origin) {
}

rt::color Source::get_color() const {
  return color;
}

rt::vector Source::get_origin() const {
  return origin;
}
