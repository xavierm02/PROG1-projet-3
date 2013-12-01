#ifndef __OBJECT_TEXTURE_H
#define __OBJECT_TEXTURE_H

#include "Point.hpp"
#include "PointTexture.hpp"
#include <memory>

class ObjectTexture {
  public:
    virtual std::shared_ptr<ObjectTexture> clone() const = 0;
    virtual PointTexture get_point_texture_at(const Point& point) const = 0;
};

#endif

