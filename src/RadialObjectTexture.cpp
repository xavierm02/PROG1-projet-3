#include "RadialObjectTexture.hpp"

#include <math.h>

RadialObjectTexture::RadialObjectTexture(const Point& origin, double scalar, double offset):// TODO take array of colors
  offset(offset),
  origin(origin),
  scalar(scalar) {
}


RadialObjectTexture* RadialObjectTexture::clone() const {
  return new RadialObjectTexture(*this);
}

double RadialObjectTexture::get_offset() const {
  return offset;
}

Point RadialObjectTexture::get_origin() const {
  return origin;
}

double RadialObjectTexture::get_scalar() const {
  return scalar;
}

PointTexture RadialObjectTexture::get_point_texture_at(const Point& point) const {
  double t = fmod(offset + (point - origin).norm() * scalar, 3.0);
  if (t <= 1) {
    return rt::color((1-t)*255, t*255, 0);
  }
  t = t - 1;
  if (t <= 1) {
    return rt::color(0, (1-t)*255, t*255);
  }
  t = t - 1;
  return rt::color(t*255, 0, (1-t)*255);
}
