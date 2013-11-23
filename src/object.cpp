#include "object.hpp"
#include "vector.hpp"
#include "ray.hpp"
#include <iostream>

rt::color object::get_color() const {
  return color;
}
