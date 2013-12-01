#ifndef __UNIFORM_OBJECT_TEXTURE_H
#define __UNIFORM_OBJECT_TEXTURE_H

#include "ObjectTexture.hpp"

class UniformObjectTexture {
  private:
    PointTexture point_texture;
  public:
    UniformObjectTexture(const PointTexture& point_texture);
    PointTexture get_point_texture() const;
    PointTexture get_point_texture_at(const Point& /*point*/) const;
};

#endif


