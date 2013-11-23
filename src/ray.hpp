#ifndef __RAY_H
#define __RAY_H

#include "color.hpp"
#include "vector.hpp"

class ray {
  private:
    rt::color color;
    rt::vector direction;
    rt::vector origin;
  public:
    ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color);
    rt::color get_color();
    rt::vector get_direction();
    rt::vector get_origin();
};

#endif
