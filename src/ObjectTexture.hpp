#ifndef __OBJECT_TEXTURE_H
#define __OBJECT_TEXTURE_H

#include "Point.hpp"
#include "PointTexture.hpp"

class ObjectTexture {
  public:
    virtual PointTexture get_texture_at(const Point& point) const = 0;
};

#endif

