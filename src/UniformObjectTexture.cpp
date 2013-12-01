#include "UniformObjectTexture.hpp"

UniformObjectTexture::UniformObjectTexture(const PointTexture& point_texture):
  point_texture(PointTexture(point_texture)) {
}

UniformObjectTexture* UniformObjectTexture::clone() const {
  return new UniformObjectTexture(*this);
}

PointTexture UniformObjectTexture::get_point_texture() const {
  return point_texture;
}

PointTexture UniformObjectTexture::get_point_texture_at(const Point& /*point*/) const {
  return point_texture;
}

/*UniformObjectTexture UniformObjectTexture::WHITE = UniformObjectTexture(PointTexture::WHITE);
UniformObjectTexture UniformObjectTexture::BLACK = UniformObjectTexture(PointTexture::BLACK);
UniformObjectTexture UniformObjectTexture::RED = UniformObjectTexture(PointTexture::RED);
UniformObjectTexture UniformObjectTexture::GREEN = UniformObjectTexture(PointTexture::GREEN);
UniformObjectTexture UniformObjectTexture::BLUE = UniformObjectTexture(PointTexture::BLUE);
UniformObjectTexture UniformObjectTexture::GREY = UniformObjectTexture(PointTexture::GREY);*/
