#include "camera.hpp"

camera::camera(const rt::vector& origin, const rt::vector& direction) {
  _origin = origin;
  _direction = direction;
}

