#ifndef __RAY_H
#define __RAY_H

#include "UnitVector.hpp"
#include "Point.hpp"

class Ray {
  private:
    UnitVector direction;
    Point origin;
    unsigned int propagations_left;

  public:
    Ray(const Point& origin, const UnitVector& direction, const unsigned int propagations_left);

    UnitVector get_direction() const;
    Point get_origin() const;
    unsigned int get_propagations_left() const;
};

#endif
