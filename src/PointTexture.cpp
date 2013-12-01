#include "PointTexture.hpp"
#include "rt/color.hpp"

PointTexture::PointTexture(const rt::color& color):
  color(color) {
}

rt::color PointTexture::get_color() const {
  return color;
}

PointTexture PointTexture::WHITE = PointTexture(rt::color(255, 255, 255));
PointTexture PointTexture::BLACK = PointTexture(rt::color(0, 0, 0));
PointTexture PointTexture::RED = PointTexture(rt::color(255, 0, 0));
PointTexture PointTexture::GREEN = PointTexture(rt::color(0, 255, 0));
PointTexture PointTexture::BLUE = PointTexture(rt::color(0, 0, 255));
PointTexture PointTexture::GREY = PointTexture(rt::color(127, 127, 127));
