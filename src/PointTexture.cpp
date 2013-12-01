#include "PointTexture.hpp"

PointTexture::PointTexture(const rt::color& color):
  color(color) {
}

rt::color PointTexture::get_color() const {
  return color;
}

PointTexture PointTexture::WHITE = PointTexture(rt::color::WHITE);
PointTexture PointTexture::BLACK = PointTexture(rt::color::BLACK);
PointTexture PointTexture::RED = PointTexture(rt::color::RED);
PointTexture PointTexture::GREEN = PointTexture(rt::color::GREEN);
PointTexture PointTexture::BLUE = PointTexture(rt::color::BLUE);
PointTexture PointTexture::GREY = PointTexture(rt::color(127, 127, 126));
