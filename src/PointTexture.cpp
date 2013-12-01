#include "PointTexture.hpp"

PointTexture::PointTexture(const rt::color& color):
  color(color) {
}

rt::color PointTexture::get_color() const {
  return color;
}
