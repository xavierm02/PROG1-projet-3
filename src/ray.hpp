#ifndef __RAY_H
#define __RAY_H

#include "color.hpp"
#include "vector.hpp"

class ray {
  private:
    rt::vector _origin;
    rt::vector _direction;
    rt::color _color;
    double _intensity;
  public:
    ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color, double intensity);
    rt::vector get_origin();
    rt::vector get_direction();
};

#endif
