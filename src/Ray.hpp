#ifndef __RAY_H
#define __RAY_H

#include "color.hpp"
#include "vector.hpp"
#include "Point.hpp"

class Ray {
  private:
    rt::vector direction;
    Point origin;
    unsigned int propagations_left;

  public:
    Ray(const Point& origin, const rt::vector& direction, const unsigned int propagations_left);

    rt::vector get_direction() const;
    Point get_origin() const;
    unsigned int get_propagations_left() const;
};

#endif
