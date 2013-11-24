#ifndef __RAY_H
#define __RAY_H

#include "color.hpp"
#include "vector.hpp"

class Ray {
  private:
    rt::color color;
    rt::vector direction;
    rt::vector origin;

  public:
    Ray(const rt::vector& origin, const rt::vector& direction, const rt::color& color);

    rt::color get_color() const;
    rt::vector get_direction() const;
    rt::vector get_origin() const;
};

#endif
