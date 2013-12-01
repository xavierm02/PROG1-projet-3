#include "UniformObjectTexture.hpp"

UniformObjectTexture::UniformObjectTexture(const PointTexture& point_texture):
  point_texture(point_texture) {
}

PointTexture UniformObjectTexture::get_point_texture() const {
  return point_texture;
}

PointTexture UniformObjectTexture::get_point_texture_at(const Point& /*point*/) const {
  return point_texture;
}
