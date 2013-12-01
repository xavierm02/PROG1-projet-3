#ifndef __RADIAL_OBJECT_TEXTURE_H
#define __RADIAL_OBJECT_TEXTURE_H

#include "ObjectTexture.hpp"

class RadialObjectTexture: public ObjectTexture {
  private:
    double offset;
    Point origin;
    double scalar;
  public:
    RadialObjectTexture(const Point& origin, double scalar, double offset);
    RadialObjectTexture* clone() const;

    double get_offset() const;
    Point get_origin() const;
    double get_scalar() const;

    PointTexture get_point_texture_at(const Point& point) const;
};

#endif
