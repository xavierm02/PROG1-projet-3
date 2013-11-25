#include "Utils.hpp"

std::ostream &operator<<(std::ostream &os, const rt::vector &vector) {
  return os << "(" << vector.x << ", " << vector.y << ", " << vector.z << ")";
}
