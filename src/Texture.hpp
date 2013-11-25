#ifndef __TEXTURE_H
#define __TEXTURE_H

#include "color.hpp"

class Texture {
  private:
    rt::color color;
  public:
    Texture(const rt::color& color = rt::color::GREEN);

    rt::color get_color() const;
};

#endif


