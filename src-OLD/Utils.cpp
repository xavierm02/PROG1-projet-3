#include "Utils.hpp"
#include "color.hpp"

std::ostream &operator<<(std::ostream &os, const rt::vector &vector) {
  return os << "<" << vector.x << ", " << vector.y << ", " << vector.z << ">";
}

std::ostream &operator<<(std::ostream& os, const rt::color& color) {
  return os << "color(" << (int) color.get_red() << ", " << (int) color.get_green() << ", " << (int) color.get_blue() << ")";
}
