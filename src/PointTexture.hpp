#ifndef __POINT_TEXTURE_H
#define __POINT_TEXTURE_H

#include "rt/color.hpp"

class PointTexture {
  private:
    rt::color color;
  public:
    PointTexture(const rt::color& color);

    rt::color get_color() const;

    static PointTexture WHITE;
    static PointTexture BLACK;
    static PointTexture RED;
    static PointTexture GREEN;
    static PointTexture BLUE;
    static PointTexture GREY;
};

#endif
