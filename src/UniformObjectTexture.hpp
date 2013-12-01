#ifndef __UNIFORM_OBJECT_TEXTURE_H
#define __UNIFORM_OBJECT_TEXTURE_H

#include "ObjectTexture.hpp"

class UniformObjectTexture: public ObjectTexture {
  private:
    PointTexture point_texture;
  public:
    UniformObjectTexture(const PointTexture& point_texture);
    UniformObjectTexture* clone() const;
    PointTexture get_point_texture() const;
    PointTexture get_point_texture_at(const Point& /*point*/) const;

    static UniformObjectTexture WHITE;
    static UniformObjectTexture BLACK;
    static UniformObjectTexture RED;
    static UniformObjectTexture GREEN;
    static UniformObjectTexture BLUE;
    static UniformObjectTexture GREY;
};

#endif


