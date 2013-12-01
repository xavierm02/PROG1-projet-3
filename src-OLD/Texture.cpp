#include "Texture.hpp"

Texture::Texture(const rt::color& color) :
  color(color) {
}

rt::color Texture::get_color() const {
  return color;
}
