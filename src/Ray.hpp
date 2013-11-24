#ifndef __RAY_H
#define __RAY_H

#include "color.hpp"
#include "vector.hpp"
#include "Point.hpp"

class Ray {
  private:
    rt::vector direction;
    Point origin;

  public:
    Ray(const Point& origin, const rt::vector& direction);

    rt::vector get_direction() const;
    Point get_origin() const;
};

#endif
